<h1>Controlador MIDI: Guitarra-Theremín</h1>

<h2>Descripción</h2>
El proyecto consistió en hacer un dispositivo innovador, el cual se basó en un controlador MIDI utilizando Arduino. Este artefacto se coloca en el cuerpo de una guitarra eléctrica, y mediante la aproximación y el alejamiento de la mano del usuario, se logra manipular el sonido a efectos de simular un theremín.

El sensor HC-SR04 calcula la distancia de la mano del usuario. Este mismo está conectado al Arduino, el cual está programado con el código que recibirá las mediciones registradas. Se utilizaron 2 softwares adicionales para simular el puerto MIDI: Hairless MIDI y LoopBe1. El primero se utilizó para convertir las señales del Arduino (vía USB) a formato MIDI. El segundo simula la conexión de un puerto MIDI de forma virtual. Luego, resta conectar la guitarra eléctrica por medio de una interfaz USB, ajustar los parámetros deseados dentro del DAW (software de edición de audio) y comenzar a utilizar el dispositivo.

<h2>Lenguaje y entorno</h2>

- <b>Arduino en Arduino IDE</b>

<h2>Software adicional</h2>

- <b> Hairless MIDI </b>
- <b> LoopBe1</b>
- <b> DAW: FL Studio 20</b>

<h2>Hardware</h2>

- <b> Arduino NANO</b>
- <b> Sensor ultrasónico HC-SR04</b>
- <b> Interfaz PreSonus AudioBox USB</b>


