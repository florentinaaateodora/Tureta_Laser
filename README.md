# Tureta_Laser

Acest proiect vizează dezvoltarea unui dispozitiv care să controleze direcția de propagare a unui fascicul laser. Acesta va permite ajustarea precisă a poziției fasciculului în toate direcțiile (sus-jos, stânga-dreapta). Pentru a realiza acest lucru, vom utiliza două servomotoare montate perpendicular, care vor asigura mișcarea laserului. 

Principalele obiective ale proiectului sunt următoarele:

1.	Controlul turetei

Implementarea unui sistem de control manual pentru fiecare servomotor, utilizând un potențiometru (joystick). Acest lucru ne va permite  să ajustam poziția fasciculului laser.

2.	Monitorizarea traiectoriei

Microcontroler-ul va fi responsabil de monitorizarea traiectoriei fasciculului. Coordonatele x și y ale fasciculului vor fi afișate pe un ecran LCD, oferind o vizualizare în timp real a poziției acestuia.
Cu ajutorul potențiometrului (joystick)  transmitem o valoare către servomotoare, acestea având valori cuprinse între 0-90 grade 


3.	Ținta fasciculului laser

Pentru realizarea țintei laser, am folosit un singur punct de detecție, acesta fiind realizat dintr-un        fotorezistor. Atunci când fotorezistorul depășește o anumită valoare prestabilită de noi, algoritmul va         aprinde  dioda led de culoare verde care va admite faptul că ținta a fost atinsă  cu succes.


