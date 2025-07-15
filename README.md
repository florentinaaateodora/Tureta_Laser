# Tureta_Laser

Acest proiect vizează dezvoltarea unui dispozitiv care să controleze direcția de propagare a unui fascicul laser. Acesta permite ajustarea precisă a poziției fasciculului în toate direcțiile (sus-jos, stânga-dreapta). Pentru acest proiect, au fost utilizate două servomotoare montate perpendicular, ce asigură mișcarea laserului. 

Principalele obiective ale proiectului:

1.	Controlul turetei

Implementarea unui sistem de control manual pentru fiecare servomotor, utilizând un potențiometru (joystick). Acest lucru permite ajustarea poziției fasciculului laser.

2.	Monitorizarea traiectoriei

Microcontroler-ul este responsabil de monitorizarea traiectoriei fasciculului. Coordonatele x și y ale fasciculului sunt afișate pe un ecran LCD, oferind o vizualizare în timp real a poziției acestuia.
Cu ajutorul potențiometrului se transmite o valoare către servomotoare, acestea având valori cuprinse între 0-90 grade 


3.	Ținta fasciculului laser

Pentru realizarea țintei laser, s-a folosit un singur punct de detecție, acesta fiind realizat dintr-un  fotorezistor. Atunci când fotorezistorul depășește o anumită valoare prestabilită de noi, algoritmul va aprinde dioda led de culoare verde care va admite faptul că ținta a fost atinsă  cu succes.


