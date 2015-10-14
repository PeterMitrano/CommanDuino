# RBE2001
rbe 2001 project

# Current Status
Line Tracking
  basic line following is solid, uses PD controller
  turning is very difficult because our line sensor is extremely close to our turning center. I've gotten it to be ok, but still not reliable

Manipulating Rods
  Putting the rod back in the reactor is extremely difficult
  getting the rod out of supply works, but to be robust we grab, pull back, and regrab
  putting the rod in the storage is ok, but occasionally we get stuck

Bluetooth:
  hearbeat is properly sent
  radiation is untested
  receiving storage/stop/supply/resume works, but is not properly parsed and used

notes for abstracting to seperate library:
  replace getTime with millis
  pass master command to scheduler constructor, instead of singleton constructor

