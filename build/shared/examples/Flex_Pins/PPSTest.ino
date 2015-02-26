#define circuit ZPUino_2

void setup() {
  // put your setup code here, to run once:
  
   // Configure pin as output
   pinMode (WAL6 , OUTPUT );
   // enable PPS on this pin
   pinModePPS (WAL6 , HIGH );
   // Map WAL6 to FlexPinOut0
   outputPinForFunction (WAL6 , 0 );  
  
   // Configure pin as output
   pinMode (WAL0 , OUTPUT );
   // enable PPS on this pin
   pinModePPS (WAL0 , HIGH );
   // Map WAL0 to FlexPinOut1
   outputPinForFunction (WAL0 , 1 );
   
  // Configure pin as input
  pinMode (WAL1 , INPUT );
  // Map pin WAL1 to FlexPinIn1
  inputPinForFunction (WAL1 , 1 );   
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
