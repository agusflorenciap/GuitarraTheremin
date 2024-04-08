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

<br />

<h1>[ENG] MIDI Controller: Guitar-Theremin</h1>

<h2>Description</h2>
The project involved creating an innovative device, which was based on a MIDI controller using Arduino. This device is installed on the body of an electric guitar, and by moving the hand closer to or further away from the device, the sound can be manipulated to simulate a theremin.

The HC-SR04 sensor calculates the distance of the user's hand, connected to Arduino programmed with code to receive and process the recorded measurements. Two additional software programs were used to simulate the MIDI port: Hairless MIDI for converting Arduino signals (via USB) to MIDI format, and LoopBe1 to create a virtual MIDI port connection. Additionally, the electric guitar is connected via a USB interface, with desired parameters adjusted within the DAW to begin using the device.
<br />

<h2>Language and environment</h2>

- <b>Arduino in Arduino IDE</b>

<h2>Additional Software</h2>

- <b> Hairless MIDI </b>
- <b> LoopBe1</b>
- <b> DAW: FL Studio 20</b>

<h2>Hardware</h2>

- <b> Arduino NANO</b>
- <b> HC-SR04 ultrasonic sensor</b>
- <b> PreSonus AudioBox USB interface</b>

