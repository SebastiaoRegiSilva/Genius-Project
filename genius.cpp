#define led 3
#define led 6
#define botao 10

// Instalar a extenção One Dark PRO - FLAT e o C/C++

bool x1, x2, x3;
int estado, erro, sequencia, fim;

void setup()
{
    pinMode(3, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(10, OUTPUT);
    estado = 1;
}

void loop()
{
    x1 = digitalRead(13);
    x2 = digitalRead(12);
    x3 = digitalRead(11);

    switch (estado)
    {

    case 1:
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, LOW);

        erro = 0;
        while (1)
        {
            x1 = digitalRead(13);
            x2 = digitalRead(12);
            x3 = digitalRead(11);
            if (x1 == 1)
            {
                break;
            }
            else if (x2 == 1 || x3 == 1)
            {
                erro = 1;
                break;
            }
        }
        if (erro == 1)
        {
            estado = 11;
        }
        else
        {
            estado = 2;
        }
        break;

    case 2:
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, LOW);
        delay(500);
        digitalWrite(6, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(10, LOW);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, LOW);

        sequencia = 0; // Criei uma variável pra armazenar qual ponto da sequencia de botões o jogador está
        erro = 0;
        fim = 0; //variavel pra avaliar se devo encerrar o loop de verificação dos botões
        while (1)
        {
            if (fim == 1)
            { //se fim é um, saio do while e sigo a execução da máquina de estados
                break;
            }
            x1 = digitalRead(13);
            x2 = digitalRead(12);
            x3 = digitalRead(11);

            switch (sequencia)
            {       // Implemento a avaliação de qual botão foi apertado
            case 0: //espero o primeiro botão da sequência
                if (x1 == 1)
                {
                    sequencia = 1; //Apertei o botão certo e sigo na avaliação da fase
                }
                else if (x2 == 1 || x3 == 1)
                {
                    erro = 1;
                    fim = 1; //Errei o botão, seto a flag de erro e fim para sair do while
                }
                break;

            case 1:
                if (x2 == 1)
                {
                    fim = 1; //Apertei o botão certo e encerro o while sem a flag de erro
                }
                else if (x1 == 1 || x3 == 1)
                {
                    erro = 1;
                    fim = 1; //Errei o botão, seto a flag de erro e fim para sair do while
                }
                break;
            }
        }
        if (erro == 1)
        {
            estado = 11;
        }
        else
        {
            estado = 3;
        }
        break;

    case 3:
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, LOW);
        delay(500);
        digitalWrite(6, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(10, LOW);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, LOW);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(10, LOW);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(3, LOW);
        digitalWrite(10, LOW);

        sequencia = 0; // Criei uma variável pra armazenar qual ponto da sequencia de botões o jogador está
        erro = 0;
        fim = 0; //variavel pra avaliar se devo encerrar o loop de verificação dos botões
        while (1)
        {
            if (fim == 1)
            { //se fim é um, saio do while e sigo a execução da máquina de estados
                break;
            }
            x1 = digitalRead(13);
            x2 = digitalRead(12);
            x3 = digitalRead(11);

            switch (sequencia)
            {       // Implemento a avaliação de qual botão foi apertado
            case 0: //espero o primeiro botão da sequência
                if (x1 == 1)
                {
                    sequencia = 1; //Apertei o botão certo e sigo na avaliação da fase
                }
                else if (x2 == 1 || x3 == 1)
                {
                    erro = 1;
                    fim = 1; //Errei o botão, seto a flag de erro e fim para sair do while
                }
                break;

            case 1:
                if (x2 == 1)
                {
                    sequencia = 2; //Apertei o botão certo e sigo na avaliação da fase
                }
                else if (x1 == 1 || x3 == 1)
                {
                    erro = 1;
                    fim = 1; //Errei o botão, seto a flag de erro e fim para sair do while
                }
                break;

            case 2:
                if (x3 == 1)
                {
                    fim = 1; //Apertei o botão certo e encerro o while sem a flag de erro
                }
                else if (x1 == 1 || x2 == 1)
                {
                    erro = 1;
                    fim = 1; //Errei o botão, seto a flag de erro e fim para sair do while
                }
                break;
            }
        }
        if (erro == 1)
        {
            estado = 11;
        }
        else
        {
            estado = 4;
        }
        break;
    }
}