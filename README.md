# Battery-pack-tester

![Output in the console](/img/output.png)

## English
An arduino battery pack tester using SMBus

Based on [this project](https://powercartel.com/projects/packprobe/), but customized to build using the platformio project
structure and to use an Arduino NANO

**NOTES:**
- Connection to battery:

  **You must handle LI-ION batteries with extreme caution. DO NOT connect anything if you are not sure about the risks!**

  You can expect that every battery have a different pinout. 
  
  You can found most of them by googling it.
  
  Even when you found the pinout for a battery given battery, you should perform some basic tests, like measuring the output of the pack with a multimeter, to be sure you found the correct diagram.
  
  Some batteries will need a resistor to simulate the laptop (usually referred as SYSTEM PRESENT/SP or BATTERY ENABLE/BE).
  
  If needed, it is something like 1Kohm.
  
  Usually, the batteries have placed the power output in the outer pins. f.e: you can found the plus on the rightmost pins and the minus on the other side
  
  Another test will be to measure pins in the middle (where the I2C signal is usually placed) against the minus terminal/s, you should obtain something around 0.5/1Meg

- Connections to the microcontroller board:
  
  Of course, you need to connect the GND's togheter
  
  Then, you can connect the BE (or SP) resistor, if needed.
  
  Then you can safely attach the SDA ans SCL signals.
  
  On the arduino side, both pins have pullup resistors (10K) and that's it. 
  
  You can change the board, but have in mind that posibly you will need to change the I2C port pins here:
  ```
  #define SDA_PORT PORTC
  #define SDA_PIN 4
  
  #define SCL_PORT PORTC
  #define SCL_PIN 5
  ```
  
  The values shown above are taken from a diagram like this one:
  
  ![Nano pinout](/img/nano-pinout.png)


## Spanish

Basado en [este proyecto](https://powercartel.com/projects/packprobe/), cutomizado para ser compilado con platformio y para una placa Arduino NANO

**NOTAS:**
- Conexion a la bateria:

  **Tenga cuidado al manipular baterias LI-ION. NO CONECTE NADA si no esta absolutamente seguro de lo que esta haciendo y los riesgos asociados!**

  Lamentablemente, cada bateria tiene un conector particular, pero por suerte casi todas tienen esto docuemntado y se puede encontrar.
  
  Incluso si se encuentra el pinout de la bateria, deberia hacer algunos tests para estar seguro de que ha encontrado el diagrama correcto.
  
  Algunas baterias necesitan una resistencia para simular la notebook (usualmente se refieren a esto como SYSTEM PRESENT/SP o BATTERY ENABLE/BE).
  
  Si se necesita, en general sera de 1Kohm.
  
  Usualmente las baterias tienen los pines en los extremos. Si de un lado esta el positivo, del otro estara el negativo.
  
  Otro test sera medir los pines del medio, donde estaran (por lo general) las señales de SCL y SDA del I2C. Deberia medirse un valor alrededor de 0.5/1Meg

- Connexiones al microcontrolador:
  
  Por supuesto, hay que conectar los negativos (GND)
  
  Despues de eso, hay que conectar el resistor de BE (or SP), si fuera necesario.
  
  Por ultimo, se pueden conectar los pines SDA y SCL.
  
  En el arduino, se necesitan dos resistores de pullup de 10K. 
  
  Puedes cambiar la placa, pero ten en mente de que posiblemente sea necesario cambiar los punes en el codigo aqui:
  ```
  #define SDA_PORT PORTC
  #define SDA_PIN 4
  
  #define SCL_PORT PORTC
  #define SCL_PIN 5
  ```
  
  Los valores de arriba se pueden encontrar en diagramas como este:
  
  ![Nano pinout](/img/nano-pinout.png)
