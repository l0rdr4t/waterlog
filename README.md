# waterlog
Managing water temperature via logging and alarms

## Solution Architecture
* The system starts with a waterproof temperature sensor minimum capability: 0 to 100 degrees Celcius plus minus 1 degree.
* Sensor provides reading to Particle.IO Photon running firmware
* Firmware maintains a temperature state, sends readings to Particle Cloud, and locally controls a relay.
* The normally open relay controls a heating element.
* The Particle Cloud will trigger a Twilio SMS function whenever a temperature state change is reported
* The Particle Cloud will trigger a Twilio SMS function whenever a Photon goes online or offline.
