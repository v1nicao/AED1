#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int entrada;
    int critico;
    struct Paciente* prox;
} Paciente;


typedef struct {
    int size;
    int currentTime;
    Paciente* inicio;
    Paciente* final;
} NoDescritor;


NoDescritor* criaFila() {
    NoDescritor* no = (NoDescritor*)malloc(sizeof(NoDescritor));
    no->size = 0;
    no->currentTime = 420;
    no->inicio = NULL;
    no->final = NULL;
    return no;
}

int retornaSaida(NoDescritor* no, int hourEntrada)
{
    int hourSaida = no->currentTime;
    if(hourEntrada == no->currentTime)
    {
        no->currentTime += 30;
        return hourSaida;
    }
    if(hourEntrada > no->currentTime)
    {
        while(hourEntrada > no->currentTime)
        {
            no->currentTime += 30;
            hourSaida = no->currentTime;
        }
        return hourSaida;
    }


    no->currentTime += 30;
    return hourSaida;
}

int filaVazia(NoDescritor* no) {
    return no->inicio == NULL;
}

void addPaciente(NoDescritor* no, int hourEntrada, int hourCritico) {
    Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));
    novoPaciente->entrada = hourEntrada;
    novoPaciente->critico = hourCritico;
    novoPaciente->prox = NULL;
    if (filaVazia(no)) {
        no->inicio = novoPaciente;
        no->final = novoPaciente;
    } else {
        no->final->prox = novoPaciente;
        no->final = novoPaciente;
    }
    no->size++;
}

void removePaciente(NoDescritor* no) {
    if (filaVazia(no)) {
        return;
    }


    Paciente* pacienteRemovido = no->inicio;
    no->inicio = no->inicio->prox;
    no->size--;
    pacienteRemovido->prox = NULL;
    free(pacienteRemovido);
}

int check(NoDescritor* no) {
    int pacientesCriticos = 0;


    while (!filaVazia(no)) {
        Paciente* paciente = no->inicio;
        int hourSaida = retornaSaida(no, paciente->entrada);
        int tempoEspera = hourSaida - paciente->entrada;


        if (tempoEspera > paciente->critico) {
            pacientesCriticos++;
        }
        removePaciente(no);
    }


    return pacientesCriticos;
}

int main() {
    int n;
    scanf("%d", &n);


    NoDescritor* no = criaFila();


    int i;
    for (i = 0; i < n; i++) {
        int hour, min, critico;
        scanf("%d %d %d", &hour, &min, &critico);


        addPaciente(no, hour*60+min, critico);
    }


    int qntCriticos = check(no);
    printf("%d", qntCriticos);


    free(no);
    return 0;
}