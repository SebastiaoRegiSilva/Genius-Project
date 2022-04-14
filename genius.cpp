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
    pinMode(pin3, OUTPUT); // LED Vermelho.
    pinMode(pin4, OUTPUT); // LED Amarelo.
    pinMode(pin5, OUTPUT); // LED Verde.
    pinMode(pin11, INPUT); // Botão do Vermelho.
    pinMode(pin12, INPUT); // Botão do Amarelo.
    pinMode(pin13, INPUT); // Botão do Verde.
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
                    break;
                }
            }
        break;
            
        // Fase 1 do jogo vai acender o verde.
        case 1:
            digitalWrite(pin5, HIGH); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            erro = 0;
            while (1)
            {
                x1 = digitalRead(pin13); // Verde.
                x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.
                
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
                estado = 2;
            
        break;

        // Fase 2 do jogo vai acender o Verde e o Vermelho.
        case 2:
            digitalWrite(pin5, HIGH); // LED Verde.
            digitalWrite(pin4, LOW); 
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
				x2 = digitalRead(pin12); // Amarelo.
                x3 = digitalRead(pin11); // Vermelho.

                // Implemento a avaliação de qual botão foi apertado.
                switch (sequencia)
                {       
                    // Espero o primeiro botão da sequência.
                    case 0: 
                        // Apertei o botão certo e sigo na avaliação da fase.
                        if (x1 == 1)
                            sequencia = 1; 
                        else if (x2 == 1 || x3 == 1)
                        {
                            // Errei o botão, seto a flag de erro e fim para sair do while.
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Apertei o botão certo e encerro o while sem a flag de erro.
                        if (x3 == 1)
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

        // Fase 3 do jogo vai acender o Verde, Vermelho e Amarelo.
        case 3:
            digitalWrite(pin5, HIGH); // Verde. 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            sequencia = 0;
            erro = 0;
            fim = 0;
            
            // Loop infinito
            while (1)
            {
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13);
                x2 = digitalRead(pin12);
                x3 = digitalRead(pin11);

                switch (sequencia)
                {       
                    case 0:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
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
                estado = 4;
            
        break;

        // Fase 4 do jogo vai acender o Verde, Vermelho, Amarelo e Verde.
        case 4:
            digitalWrite(pin5, HIGH); // Verde. 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, HIGH); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            
            sequencia = 0;
            erro = 0;
            fim = 0;
            
            // Loop infinito
            while (1)
            {
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13);
                x2 = digitalRead(pin12);
                x3 = digitalRead(pin11);

                switch (sequencia)
                {       
                    case 0:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
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
                estado = 5;
            
        break;
    
        // Fase 5 do jogo vai acender o Verde, Vermelho, Amarelo, Verde e Vermelho.
        case 5:
            digitalWrite(pin5, HIGH); // Verde. 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            sequencia = 0;
            erro = 0;
            fim = 0;
            
            // Loop infinito
            while (1)
            {
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13);
                x2 = digitalRead(pin12);
                x3 = digitalRead(pin11);

                switch (sequencia)
                {       
                    case 0:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
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
                estado = 6;
            
        break;

        // Fase 6 do jogo vai acender o Verde, Vermelho, Amarelo, Verde, Vermelho e Amarelo.
        case 6:
            digitalWrite(pin5, HIGH); // Verde. 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            sequencia = 0;
            erro = 0;
            fim = 0;
            
            // Loop infinito
            while (1)
            {
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13);
                x2 = digitalRead(pin12);
                x3 = digitalRead(pin11);

                switch (sequencia)
                {       
                    case 0:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
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
                estado = 7;
            
        break;

        // Fase 7 do jogo vai acender o Verde, Vermelho, Amarelo, Verde, Vermelho ,Amarelo e Verde.
        case 7:
            digitalWrite(pin5, HIGH); // Verde. 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            sequencia = 0;
            erro = 0;
            fim = 0;
            
            // Loop infinito
            while (1)
            {
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13);
                x2 = digitalRead(pin12);
                x3 = digitalRead(pin11);

                switch (sequencia)
                {       
                    case 0:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 6:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
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
                estado = 8;
            
        break;

        // Fase 8 do jogo vai acender o Verde, Vermelho, Amarelo, Verde, Vermelho ,Amarelo, Verde e Vermelho.
        case 8:
            digitalWrite(pin5, HIGH); // Verde. 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            sequencia = 0;
            erro = 0;
            fim = 0;
            
            // Loop infinito
            while (1)
            {
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13);
                x2 = digitalRead(pin12);
                x3 = digitalRead(pin11);

                switch (sequencia)
                {       
                    case 0:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 6:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 7:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
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
                estado = 9;
            
        break;

        /* Fase 9 do jogo vai acender o Verde, Vermelho, 
            Amarelo, Verde, Vermelho ,Amarelo, Verde, Vermelho e Amarelo.
        */
        case 9:
            digitalWrite(pin5, HIGH); // Verde. 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            
            sequencia = 0;
            erro = 0;
            fim = 0;
            
            // Loop infinito
            while (1)
            {
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13);
                x2 = digitalRead(pin12);
                x3 = digitalRead(pin11);

                switch (sequencia)
                {       
                    case 0:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 6:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 7:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 8:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
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
                estado = 10;
            
        break;

        /* Fase 9 do jogo vai acender o Verde, Vermelho, 
            Amarelo, Verde, Vermelho ,Amarelo, Verde, Vermelho, Amarelo e Verde.
        */
        case 10:
            digitalWrite(pin5, HIGH); // Verde. 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW); 
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, HIGH); // Vermelho.
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); 
            digitalWrite(pin4, HIGH); // Amarelo.
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW); // Verde.
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);
            delay(500);
            digitalWrite(pin5, LOW);
            digitalWrite(pin4, LOW);
            digitalWrite(pin3, LOW);

            
            sequencia = 0;
            erro = 0;
            fim = 0;
            
            // Loop infinito
            while (1)
            {
                if (fim == 1)
                    break;
                
                x1 = digitalRead(pin13);
                x2 = digitalRead(pin12);
                x3 = digitalRead(pin11);

                switch (sequencia)
                {       
                    case 0:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 1:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 2:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 3:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 4:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 5:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 6:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 7:
                        // Pressiona o botão que liga o vermelho.
                        if (x3 == 1)
                            sequencia = 2;
                        else if (x1 == 1 || x2 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 8:
                        // Pressiona o botão que liga o amarelo.
                        if (x2 == 1)
                            fim = 1;
                        else if (x1 == 1 || x3 == 1)
                        {
                            erro = 1;
                            fim = 1; 
                        }
                    break;

                    case 9:
                        // Pressiona o botão que liga o verde.
                        if (x1 == 1)
                            sequencia = 1;
                        else if (x2 == 1 || x3 == 1)
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
                estado = 11;
            
        break;

        case 11:
        // Implementar depois.
    }
}