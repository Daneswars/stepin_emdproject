# Test Plans

|  Test ID | Description  | Input  | Output  | Status |
|---|---|---|---|---|
| TID_01  | Is person seated  | switch button=1| switch button=1| PASS  |
| TID_02  | Is person not seated  | switch button=0| switch button=0 | PASS  |
| TID_03  | Temperature Request | Temp=0| heater=Off | PASS  |
| TID_04  | Temperature Request | Temp=201| heater=201 degree generation | PASS  |
| TID_05  | Temperature Request | Temp=220| heater=220 degree generation | PASS  |
| TID_06  | Temperature Request | Temp=250| heater=250 degree generation | PASS  |
| TID_07  | Temperature Request | Temp=331| heater=331 degree generation | PASS  |
| TID_08  | LED ON | Button=1 && Heater=1| LED=1 | PASS  |
| TID_09  | LED OFF | Button=0 && Heater=0| LED=0 | PASS  |
| TID_10  | LCD Display | Temperature :)<br />201 deg Cel| Temperature :)<br />201 deg Cel| PASS  |
