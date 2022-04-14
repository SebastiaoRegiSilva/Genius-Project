#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin11 11
#define pin12 12
#define pin13 13

// Variáveis globais.
bool x1, x2, x3, erro, fim;
int estado, sequencia;

void setup()
{
    estado = 0;
    pinMode(pin2, OUTPUT); // Buzzer 
    pinMode(pin3, OUTPUT); // LED Amarelo
    pinMode(pin4, OUTPUT); // LED Vermelho
    pinMode(pin5, OUTPUT); // LED Verde
    pinMode(pin11, INPUT);
    pinMode(pin12, INPUT);
    pinMode(pin13, INPUT);
}

void loop()
{
    x1 = digitalRead(pin13);
    x2 = digitalRead(pin12);
    x3 = digitalRead(pin11);

    switch (estado)
    {
        // Fase de inicialização do jogo.    
        case 0:
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            
            erro = 0;
            // Loop infinito.
            while (1)
            {
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Vermelho.
                x3 = digitalRead(pin11); // Amarelo.
                if (x1 == 1 || x2 == 1 || x3 == 1)
                {
                    estado = 1;
                    break;
                }
            }
            break;
            
        case 1:
            digitalWrite(pin5, HIGH); // Verde.
            digitalWrite(pin4, LOW); // Vermelho.
            digitalWrite(pin3, LOW); // Amarelo
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            erro = 0;
            while (1)
            {
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Vermelho.
                x3 = digitalRead(pin11); // Amarelo.
                
                if (x1 == 1)
                    break;
                else if (x2 == 1 || x3 == 1)
                {
                    erro = 1;
                    break;
                }
            }
            
            if (erro == 1)
                estado = 11;
            else
            {
                estado = 2;
                delay(500); // Segurar o LED acesso. 
            }
            
            break;

        case 2:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Amarelo.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // Led Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            erro = 0;
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Vermelho.
                x3 = digitalRead(pin11); // Amarelo.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Apertei o botão certo e sigo na avaliação da fase.
                        if (x3 == 1)
                            sequencia = 1; 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                        break;

                    case 1:
                        // Apertei o botão certo e encerro o while sem a flag de erro.
                        if (x1 == 1)
                            fim = 1; 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                        break;
                }
            }
            
            // Verificação se há erros.
            if (erro == 1)
                estado = 11;
            else
                estado = 3;
            
            break;
    }
}