// Atvidade realizada pelo BRUNO e Sebastião Willian

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
    pinMode(pin2, OUTPUT); // Buzzer.
    pinMode(pin3, OUTPUT); // LED Vermelho.
    pinMode(pin4, OUTPUT); // LED Amarelo.
    pinMode(pin5, OUTPUT); // LED Verde.
    pinMode(pin11, INPUT); // Botão do LED Vermelho
    pinMode(pin12, INPUT); // Botão do LED Amarelo.
    pinMode(pin13, INPUT); // Botão do LED Verde.
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
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.
                if (x1 == 1 || x2 == 1 || x3 == 1)
                {
                    estado = 1;
                    delay(500); 
                    break;
                }
            }
        break;
            
        // Fase 1 do jogo vai acender o Verde.
        case 1:
            digitalWrite(pin5, HIGH); // Verde.
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            while (1)
            {
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.
                
                // Verificar se o botão verde foi pressionado.
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
                delay(500); 
            }
            
        break;

        // Fase 2 do jogo vai acender o Vermelho e o Verde.
        case 2:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        }
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                            fim = 1; 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
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
            {
                estado = 3;
                delay(500); 
            }

        break;

        // Fase 3 do jogo vai acender o Vermelho, Verde e Amarelo.
        case 3:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        }
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 2; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                            fim = 1; 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
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
            {
                estado = 4;
                delay(500); 
            }

        break;

        // Fase 4 do jogo vai acender o Vermelho, Verde, Amarelo e Vermnelho.
        case 4:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        }
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 2; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 3; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                            fim = 1; 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
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
            {
                estado = 5;
                delay(500); 
            }
        break;

        // Fase 5 do jogo vai acender o Vermelho, Verde, Amarelo, Vermelho e Verde.
        case 5:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        }
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 2; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 3; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 4; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                            fim = 1; 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
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
            {
                estado = 6;
                delay(500); 
            }
        break;

        // Fase 6 do jogo vai acender o Vermelho, Verde, Amarelo, Vermelho, Verde e Amarelo.
        case 6:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 2; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 3; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 4; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 5; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                            fim = 1; 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
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
            {
                estado = 7;
                delay(500); 
            }
        break;

        // Fase 7 do jogo vai acender o Vermelho, Verde, Amarelo, Vermelho, Verde, Amarelo e Vermelho.
        case 7:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 2; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 3; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 4; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 5; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 6; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 6: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                            fim = 1; 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
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
            {
                estado = 8;
                delay(500); 
            }
        break;

        // Fase 8 do jogo vai acender o Vermelho, Verde, Amarelo, Vermelho, Verde, Amarelo, Vermelho e Verde.
        case 8:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        }
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 2; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 3; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 4; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 5; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 6; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 6: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 7; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 7:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                            fim = 1; 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
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
            {
                estado = 9;
                delay(500); 
            }
        break;

        // Fase 9 do jogo vai acender o Vermelho, Verde, Amarelo, Vermelho, Verde, Amarelo, Vermelho, Verde e Amarelo.
        case 9:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 2; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 3; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 4; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 5; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 6; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 6: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 7; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 7:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 8; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 8:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                            fim = 1; 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
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
            {
                estado = 10;
                delay(500); 
            }
        break;

        // Fase 10 do jogo vai acender o Vermelho, Verde, Amarelo, Vermelho, Verde, Amarelo, Vermelho, Verde, Amarelo e Vermelho.
        case 10:
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, HIGH); // LED Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW); 
            digitalWrite(pin3, HIGH); // LED Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            // Criei uma variável pra armazenar qual ponto da sequência de botões o jogador está.
            sequencia = 0; 
            
            // Variável pra avaliar se devo encerrar o loop de verificação dos botões.
            fim = 0;
            
            // Loop infinito.
            while (1)
            {
                // Se fim for igual a um, saio do while e sigo a execução da máquina de estados.
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 1; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 2; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 3; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 4; 
                            delay(500);
                        } 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 5; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 6; 
                            delay(500);
                        }
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 6: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                        {
                            sequencia = 7; 
                            delay(500);
                        }
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 7:
                        // Verifica se o botão verde foi pressionado.
                        if (x1 == 1)
                        {
                            sequencia = 8; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x3 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 8:
                        // Verifica se o botão amarelo foi pressionado.
                        if (x2 == 1)
                        {
                            sequencia = 9; 
                            delay(500);
                        } 
                        // Errei o botão, seto a flag de erro e fim para sair do while.
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 9: 
                        // Verifica se o botão vermelho foi pressionado.
                        if (x3 == 1)
                            fim = 1; 
                        else if (x2 == 1 || x1 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
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
            {
                // Estado que venceu o jogo.
                estado = 12;
                delay(500); 
            }
        break;

        // Bloco de erro no processar das fases. O LED Vermelho deve piscar 3 vezes.
        case 11:
            // Laço de repetição para piscar o LED Vermelho 3 VEZES.
            for(int i = 0; i <= 2; i++)
            {
                // Soar o Buzzer.
              	digitalWrite(pin2, HIGH); // Buzzer.
                digitalWrite(pin5, LOW);
                digitalWrite(pin4, LOW); 
                digitalWrite(pin3, HIGH); // LED Vermelho.
                delay(300);
                digitalWrite(pin2, LOW);
                digitalWrite(pin5, LOW);
                digitalWrite(pin4, LOW);
                digitalWrite(pin3, LOW);
                delay(300);
            }
        
            // Retornar ao CASE 0 que é o início do jogo
            estado = 0;
        break;

        // Bloco quem venceu o jogo.
        case 12:
            // Laço de repetição para piscar o LED Verde 3 VEZES, indicando que venceu o jogo.
            for(int i = 0; i <= 2; i++)
            {
                digitalWrite(pin5, HIGH); // LED Verde. 
                digitalWrite(pin4, LOW); 
                digitalWrite(pin3, LOW);
                delay(300);
                digitalWrite(pin5, LOW);
                digitalWrite(pin4, LOW);
                digitalWrite(pin3, LOW);
                delay(300);
            }
        
            // Retornar ao CASE 0 que é o início do jogo.
            estado = 0;
        
        break;    
    }
}