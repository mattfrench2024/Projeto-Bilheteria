using namespace std;

#define FILEIRAS 15  // Definindo o número de fileiras no teatro
#define POLTRONAS 40 // Definindo o número de poltronas por fileira

// Declaração da matriz de ocupação, onde cada posição representa uma poltrona no teatro
// O valor inicial é um ponto '.' para representar que a poltrona está vaga
char teatro[FILEIRAS][POLTRONAS];

// Função para inicializar o teatro (todas as poltronas começam vazias)
void inicializarTeatro() {
    // Percorre todas as fileiras e poltronas, inicializando todas as poltronas como vazias
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            teatro[i][j] = '.';  // '.' significa lugar vago
        }
    }
}

// Função para mostrar o mapa de ocupação do teatro
void mostrarMapa() {
    cout << "Mapa de Ocupacao: " << endl;
    // Percorre todas as fileiras e poltronas e imprime o estado de cada uma
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            cout << teatro[i][j] << " ";  // Mostra '.' para poltronas vagas e '#' para ocupadas
        }
        cout << endl;  // Pula linha após cada fileira
    }
}

// Função para calcular o faturamento com base nas poltronas ocupadas
void calcularFaturamento(int &totalOcupados, double &valorBilheteira) {
    totalOcupados = 0;   // Inicializa a quantidade de lugares ocupados
    valorBilheteira = 0.0;  // Inicializa o valor da bilheteira

    // Percorre todas as fileiras e poltronas
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < POLTRONAS; j++) {
            if (teatro[i][j] == '#') {  // Se a poltrona estiver ocupada
                totalOcupados++;  // Conta o número de lugares ocupados

                // Determina o valor do ingresso baseado na fileira
                if (i < 5) {  // Fileiras 1 a 5
                    valorBilheteira += 50.00;
                } else if (i < 10) {  // Fileiras 6 a 10
                    valorBilheteira += 30.00;
                } else {  // Fileiras 11 a 15
                    valorBilheteira += 15.00;
                }
            }
        }
    }
}

// Função para reservar uma poltrona no teatro
void reservarPoltrona() {
    int fileira, poltrona;

    // Solicita o número da fileira e da poltrona ao usuário
    cout << "Digite o numero da fileira (1 a 15): ";
    cin >> fileira;
    cout << "Digite o numero da poltrona (1 a 40): ";
    cin >> poltrona;

    // Verifica se os números são válidos (fileira entre 1 e 15, poltrona entre 1 e 40)
    if (fileira < 1 || fileira > 15 || poltrona < 1 || poltrona > 40) {
        cout << "Entrada invalida! Tente novamente." << endl;
        return;
    }

    // Ajusta os números para os índices corretos da matriz (0 a 14 e 0 a 39)
    fileira--;
    poltrona--;

    // Verifica se a poltrona já está ocupada
    if (teatro[fileira][poltrona] == '#') {
        cout << "Erro: a poltrona ja esta ocupada!" << endl;
    } else {
        teatro[fileira][poltrona] = '#';  // Marca a poltrona como ocupada
        cout << "Reserva realizada com sucesso!" << endl;
    }
}

int main() {
    int opcao;
    int totalOcupados = 0;
    double valorBilheteira = 0.0;

    // Inicializa o teatro com todas as poltronas vagas
    inicializarTeatro();

    // Menu do programa para o usuário escolher as opções
    do {
        cout << "\nMenu de Opcoes:" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mostrar mapa de ocupacao" << endl;
        cout << "3. Faturamento" << endl;
        cout << "0. Finalizar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Processa a opção escolhida pelo usuário
        switch (opcao) {
            case 0:
                cout << "Finalizando programa..." << endl;
                break;
            case 1:
                reservarPoltrona();  // Chama a função de reserva
                break;
            case 2:
                mostrarMapa();  // Exibe o mapa de ocupação
                break;
            case 3:
                calcularFaturamento(totalOcupados, valorBilheteira);  // Calcula o faturamento
                cout << "Qtde de lugares ocupados: " << totalOcupados << endl;
                cout << "Valor da bilheteira: R$ " << valorBilheteira << endl
