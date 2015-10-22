#include "BlinkAlot.h"
#include "Blink.h"

//here we blink 4 times at various frequencies, and sometimes in parallel!
BlinkAlot::BlinkAlot() : CommandGroup("so much blinking"){
  addSequential(new Blink(500));
  addSequential(new Blink(100));
  //notice how we get weird behavior when we do this
  // this is because sometimes, we're setting the LED high then low at the same time
  // whoops!
  // you can try to fix this by one small edit to the Blink class
  addParallel(new Blink(200));
  addSequential(new Blink(300));
}
