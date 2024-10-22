#include "rm.h"

sem_mutex_t *m;


// Função que cada tarefa executará
void* executar_tarefa(void* arg) {
    Tarefa* tarefa = (Tarefa*)arg;
    while (1) {
    	mutex_enter_critical(&m); // Proteger o acesso
        if (tarefa->restante_exec > 0) {
            tarefa->restante_exec--;
            printf("Executando tarefa %d\n", tarefa->id);
        }
        mutex_exit_critical(&m); // Liberar o mutex
        sleep(1); // Simula o tempo de execução
    }
    return NULL;
}

// Função para verificar se uma tarefa está pronta para ser executada
int tarefa_pronta(Tarefa *tarefa, int tempo_atual) {
    return (tempo_atual % tarefa->periodo == 0);
}
