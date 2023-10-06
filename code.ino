#define A 9
#define B 10
#define C 4
#define D 5
#define E 6
#define F 8
#define G 7

#define pulsador_sube 13
#define pulsador_baja 12
#define pulsador_reset 11

#define display_on 25
#define decena A4
#define unidad A5
#define apagados 1

int contador_digito = 0;
int sumaPrevia = 1;
int restaPrevia = 1;
int resetPrevia = 1;

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);

    pinMode(pulsador_sube, INPUT_PULLUP);
    pinMode(pulsador_baja, INPUT_PULLUP);
    pinMode(pulsador_reset, INPUT_PULLUP);

    pinMode(decena, OUTPUT);
    pinMode(unidad, OUTPUT);
  
    digitalWrite(decena, LOW);
    digitalWrite(unidad, LOW);

    Serial.begin(9600);
}

void loop()
{	
    
    int pressed = keyPressed();
    if (pressed == pulsador_sube)
    {
        contador_digito++;
        if (contador_digito > 99)
        {
            contador_digito = 0;
        }
    }
    else if (pressed == pulsador_baja)
    {
        contador_digito--;
      
        if (contador_digito < 0)
        {
            contador_digito = 99;
        }
    }
    else if (pressed == pulsador_reset)
    {
        contador_digito = 0;
    }
    Serial.println(contador_digito);
    printCount(contador_digito);
 	
  
}

void printDigit(int digit)
{
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
	delay(15);
    switch (digit)
    {
    case 0:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        break;
    case 1:
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        break;
    case 2:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        break;
    case 3:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(D, HIGH);
        break;
    case 4:
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(F, HIGH);
        break;
    case 5:
        digitalWrite(A, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        break;
    case 6:
        digitalWrite(A, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        break;
    case 7:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        break;
    case 8:
        digitalWrite(A, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(D, HIGH);
        digitalWrite(E, HIGH);
        digitalWrite(F, HIGH);
        digitalWrite(G, HIGH);
        break;
    case 9:
        digitalWrite(A, HIGH);
        digitalWrite(G, HIGH);
        digitalWrite(C, HIGH);
        digitalWrite(B, HIGH);
        digitalWrite(F, HIGH);
        break;
    }
}

void prendeDigito(int digito)
{
    digitalWrite(unidad, LOW);
    digitalWrite(decena, LOW);
	delay(150);
    if (digito == unidad)
    {
        digitalWrite(unidad, HIGH);
      	digitalWrite(decena, LOW);
      delay(100);
      
    }
    else if (digito == decena)
    {
        digitalWrite(decena, HIGH);
      	digitalWrite(unidad, LOW);
     delay(100);
      
    }
}

void printCount(int count)
{
    
    
	int decenas = count / 10;
    prendeDigito(decena);
    printDigit(decenas);
  	int unidades = count % 10;
    prendeDigito(unidad);
    printDigit(unidades);
    
}
int keyPressed(void)
{
    int suma = digitalRead(pulsador_sube);
    int resta = digitalRead(pulsador_baja);
    int reset = digitalRead(pulsador_reset);
  
    if (suma)
    {
        sumaPrevia = 1;
    }
    if (resta)
    {
        restaPrevia = 1;
    }
    if (reset)
    {
        resetPrevia = 1;
    }

    if (suma == 0 && suma != sumaPrevia)
    {
        sumaPrevia = suma;
        return pulsador_sube;
    }
    if (resta == 0 && resta != restaPrevia)
    {
        restaPrevia = resta;
        return pulsador_baja;
    }
    if (reset == 0 && reset != resetPrevia)
    {
        resetPrevia = reset;
        return pulsador_reset;
    }
    return 0;
}