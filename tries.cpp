/*
       TRABALHO ESTRUTURA DE DADOS
Estudantes: Igmar Flores e Isabelle Bicudo
Professor: Fabio Henrique Viduani Martinez 
*/

#include <iostream>
#include <string>
using namespace std;

class No {
public:
    No* filhos[26];//array para armazenar os filhos
    bool fimpalavra;//se é o fim da palavra 
    
    // Inicializando nó
    No() {
        fimpalavra = false; // Inicializa como não sendo o fim de uma palavra
        
        for (int i = 0; i < 26; i++) {
            filhos[i] = nullptr;//inicializando filhos como null
        }
    }
};

class Trie {
public:
    No* raiz;

    Trie() {//iniciando a trie como vazia
        raiz = new No();
    }

    void inserirTrie(const std::string& W) {
        No* x = raiz;
        int k = W.size();

        for (int h = 0; h < k; h++) {
            int j = W[h] - 'a';
            if (x->filhos[j] == nullptr) {
                x->filhos[j] = new No();//se filho nao existir cria novo nó
            }
            x = x->filhos[j]; //indo para prox no
        }

        x->fimpalavra = true;//último nó é fim da palavra
    }

    void buscarTrie(No* x, const string& w) {
        int k = w.size();
        for (int l = 0; l < k; l++) {
            int j = w[l] - 'a';
            if (x->filhos[j] == nullptr) {
                cout << "Nenhuma palavra" <<endl;
                return;
            }
            x = x->filhos[j];//move para prox no
        }

        buscaautomatica(x, w);//faz a busca do prefixo 
    }

private:
    void buscaautomatica(No* x, string palavra) {
        if (x == nullptr) {
            return;
        }

        if (x->fimpalavra) {
            cout << palavra << endl;
        }

        for (int i = 0; i < 26; i++) {
            if (x->filhos[i] != nullptr) {
                char letra = 'a' + i;
                buscaautomatica(x->filhos[i], palavra + letra);
            }
        }
    }
};

int main() {
    Trie trie;
    string palavra, pref;

    // inseririndo as palavras na trie
    while (true) {
        cin>>palavra;
        if(palavra == "#"){
            break;
        }
        trie.inserirTrie(palavra);
    }

    // buscando o prefixo
    while (true) {
        cout << ">> ";
        cin >> pref;

        if (pref == "#") {
            break;
        }

        // resultado 
        trie.buscarTrie(trie.raiz, pref);
    }

    return 0;
}