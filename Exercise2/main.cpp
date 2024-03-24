#include <iostream>
#include <fstream>

double mappa(double x)
{
    //mappo i valori dall'intervallo [1,5] all'intervallo [-1,2]
    double y = (3.0/4.0)*x-(7.0/4.0);
    return y;
}

int main()
{
    //apro il file in lettura
    std::string fileNameInput = "data.csv";
    std::ifstream fileDatiInput(fileNameInput);

    //se il file non esiste stampa "il file non esiste"
    if(fileDatiInput.fail())
    {
        std::cerr << "Il file " << fileNameInput << " non esiste." << std::endl;
        return 1;
    }

    //apro il file in scrittura
    std::string fileNameOutput = "results.csv";
    std::ofstream fileDatiOutput(fileNameOutput);

    //se il file non è stato creato, avverte
    if(fileDatiOutput.fail())
    {
        std::cerr << "Il file " << fileNameOutput << " non e' stato creato." << std::endl;
        return 2;
    }

    //imposto la precisione per i valori in output
    fileDatiOutput << std::scientific;
    fileDatiOutput << std::setprecision(16);

    fileDatiOutput << "# N Mean" << "\n";

    //inizializzo:
    double value = 0.0;
    double somma = 0.0;
    unsigned int conto = 1;

    //calcolo i valori di output
    while (fileDatiInput >> value)
    {
        double valore = mappa(value);

        somma = somma + valore;
        double media = somma/conto;

        fileDatiOutput << conto << " " << std::scientific << std::setprecision(16) << media << std::endl;
        conto = conto + 1;
    }
    //chiudo i file che ho aperto
    fileDatiInput.close();
    fileDatiOutput.close();
    return 0;
}
