int valor = 0; //distancia leída
int ultValor = 0; //anterior distancia registrada
int distanciaMax= 20; //distancia máxima que registrará el sensor


const int pinTrigger = 9;
const int pinEcho = 8;

long duracion;
int distancia;

int pinSensor = 0;
int valorSensor= 0;

#define CC 0xB  /*CC es control change: es un tipo de mensaje MIDI que engloba a la vez 128 posibles mensajes de control
                  distintos: todos afectan de alguna forma la calidad del sonido (ej, el volumen, modulación, reverb, etc).
                 0xB = 11 en decimal. CC en 11 indica mensaje de Expresión. Vale 127 x defecto. Trabaja en conjunto con
                 el Volumen (7); abajo. */
#define VOLUMEN_CANAL 0x07

const int canal1=1; //para poder controlar hasta 3 efectos distintos
const int canal2=2;
const int canal3=3;


void setup ()
{
  pinMode (pinTrigger, OUTPUT);  //seteo sensor
  pinMode (pinEcho, INPUT);

  Serial.begin(115200);       /* configura MIDI y escucha todos los canales. La velocidad del puerto MIDI (115200 baudios) 
                              tiene que ser la misma que la usada en el Hairless MIDI */
}

void loop ()
{
       LecturaSensor(canal1);
       LecturaSensor(canal2);
       LecturaSensor(canal3);
}


/*el formato del mensaje para enviar via serial. creo una nueva estructura de datos, que puede guardar 3 bytes a la vez. 
 así es más fácil de enviar como MIDI (porque el MIDI se compone de 3 bytes: uno de status, y otros dos restantes de datos)*/
typedef struct {
  unsigned int canal : 4;   // medio byte para indiciar el canal MIDI (0-15) (canal y status están invertidos porque
                            // arduino es little endian: los bits - significativos se almacenan en la posición + baja
  unsigned int status : 4;  // medio byte para el satus del mensaje (NOTE_ON, NOTE_OFF o CC (control change))
  uint8_t dato1;            // 2do byte : primer valor (0-127), número de controlador o núm de nota
  uint8_t dato2;            // 3er  byte: segundo valor (0-127), valor del controlador o velocidad
}
t_mensajeMidi;       // a la estructura la llamo t_mensajeMidi


void enviarMIDI(uint8_t status, uint8_t canal, uint8_t dato1, uint8_t dato2) {
  t_mensajeMidi mensaje;
  mensaje.status = status & 0xF; //15 en decimal
  mensaje.canal = (canal-1) & 0xF; // los canales empiezan de 0 (0000 es el canal 1, y 1111 es el canal 16)
  mensaje.dato1 = dato1 & 0x7F; //127
  mensaje.dato2 = dato2 & 0x7F;//127
  Serial.write((uint8_t *)&mensaje,3);
}


void LecturaSensor(int canal)
{

  digitalWrite (pinTrigger, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite (pinTrigger, LOW);
  
  duracion = pulseIn(pinEcho, HIGH);        /*pulseIn lee la duración del pulso enviado por el pinEcho
                                            el sensor captando la distancia. esta última fórmula es para convertir a cm.*/
  distancia = duracion*0.034/2;            
  

  if (distancia<=distanciaMax) //si es válida la distancia detectada
  {
     valor = (distancia * 6.35); //para que entre en el rango midi
     if   ((valor!=ultValor+15) || (valor!=ultValor-15)) /*si el valor leído es distinto al valor anterior +-15 de error, se
                                                         manda el mensaje MIDI (para que no efectúe mensajes MIDI con cambios en
                                                         la distancia poco significativos)*/
     {
     enviarMIDI(CC, canal, VOLUMEN_CANAL, valor);
     ultValor = valor;
     delay(25); //espera 25ms entre cada pin. serían 40 pines x segundo
     }  
      
  }
}


 
