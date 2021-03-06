
const static short RGBlength;
const static short RGBhight;

//Buffers for the LED matrix

uint_16 buffA[RGBlength][RGBhight];
uint_16 buffA[RGBlength][RGBhight];
bool useBuff;

int main(int argc,char *argv[]){
	setup();
	loop();
	return 0;
}
void loop(){
	uint_16 ** toUse;
	while(volatile true){
		if(useBuff)
			toUse=buffA;
		else	
			toUse=buffB;
		useBuff=!useBuff;
		for(short x=RGBlength-1;x>=0;--x)
			for(short y=RGBhight-1;y>=0;--y)
				//TODO Matrix update
			
		//Todo Send audio signal
	}	
}

int setup(){
	#ifdef DEBUG
		initUART(BAUDRATE);
	#endif
	// set timer0 counter initial value to 0
	TCNT0=0x00;
	// start timer0 with /1024 prescaler
	TCCR0 = (1<<CS02) | (1<<CS00);
	// set timer1 counter initial value to 0
	TCNT1=0x00;
	//start timer1 with /1024 prescaler
	TCCR1 = (1<<CS12) | (1<<CS10);
	
	//TODO Configure pins that will fire interrupt on state change ( 2 needed)
	
	//global interrupt enable
	gie();
}
//NFC Interrupt Pin set high
ISR(PCINT2_vect)
{
    //Process NFC data
}
//Strike Detector Interrupt Pin set high
ISR(PCINT1_vect)
{
    //Process Strike Detector
}
ISR(TIMER1_OVF_vect) {
	//SPI out next row/column for LEDMatrix "When should I hit my damn hammer"
}

ISR(TIMER0_OVF_vect) {
	//SPI out next row/column for LEDMatrix WeponDisplay
}

initSPI(){
	// Set MOSI, SCK as Output
    DDRB = (1<<5)|(1<<3);
    // Enable SPI, Set as Master
    //Prescaler: Fosc/16, Enable Interrupts
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);	
}

unsigned char comSPI (unsigned char data)
{
    // Load data into the buffer
    SPDR = data;
 
    //Wait until transmission complete
    while(!(SPSR & (1<<SPIF) ));
 
    // Return received data
    return(SPDR);
}