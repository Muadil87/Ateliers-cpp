#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Fonction utilitaire
float calculInteret(const float solde, const float taux) {
    if (taux < 0) throw invalid_argument("Taux d'intérêt négatif");
    return solde * (1 + taux / 100);
}

class Client {
private:
    int id;
    string nom;
    string prenom;
    
public:
    // Constructeur par défaut
    Client() : id(0), nom(""), prenom("") {}
    
    // Constructeur avec paramètres
    Client(int id, const string& nom, const string& prenom) 
        : id(id), nom(nom), prenom(prenom) {
        if (id < 0) throw invalid_argument("ID client invalide");
    }
    
    // Constructeur de copie
    Client(const Client &autre) 
        : id(autre.id), nom(autre.nom), prenom(autre.prenom) {}
    
    // Destructeur (pas besoin d'affichage)
    ~Client() {}
    
    // Méthode d'affichage
    void afficher() const {
        cout << "Client " << id << ": " << nom << " " << prenom << endl;
    }
};

class Compte {
private:
    int numero;
    float solde;
    Client* client;
    static int nombreComptes; // Variable statique pour compter les comptes
    
public:
    // Constructeur par défaut
    Compte() : numero(0), solde(0), client(nullptr) {
        nombreComptes++;
    }
    
    // Constructeur avec paramètres
    Compte(int num, float sld, Client* clt) 
        : numero(num), solde(sld), client(nullptr) {
        if (num < 0) throw invalid_argument("Numéro de compte invalide");
        if (clt == nullptr) throw invalid_argument("Client invalide");
        client = new Client(*clt); // Copie profonde du client
        nombreComptes++;
    }
    
    // Constructeur de copie
    Compte(const Compte& autre) 
        : numero(autre.numero), solde(autre.solde), 
          client(autre.client ? new Client(*autre.client) : nullptr) {
        nombreComptes++;
    }
    
    // Destructeur
    ~Compte() {
        delete client; // Libération de la mémoire
        nombreComptes--;
    }
    
    // Méthode d'affichage
    void afficher() const {
        cout << "Compte " << numero << " - Solde: " << solde << endl;
        if (client) {
            client->afficher();
        }
    }
    
    // Méthode statique pour afficher le nombre de comptes
    static void afficherNombreComptes() {
        cout << "Nombre total de comptes: " << nombreComptes << endl;
    }
    
    void setSolde(const float sld) {
        if (sld < 0) throw invalid_argument("Solde négatif");
        solde = sld;
    }
    
    float getSolde() const { return solde; }
    int getNumero() const { return numero; }
};

// Initialisation de la variable statique
int Compte::nombreComptes = 0;

int main() {
    try {
        // 1. Création de clients
        Client client1(1, "Bahlouli", "Adil");
        Client client2(2, "Ahmadi", "Karim");
        
        // 2. Création de comptes
        Compte compte1(1001, 1500.0f, &client1);
        Compte compte2(1002, 2500.0f, &client2);
        
        // Affichage des informations
        cout << "\n État initial des comptes" << endl;
        compte1.afficher();
        compte2.afficher();
        Compte::afficherNombreComptes();
        
        // 3. Test du constructeur de copie
        cout << "\nTest de la copie " << endl;
        Compte compte3 = compte1;
        compte3.afficher();
        Compte::afficherNombreComptes();
        
        // 4. Application des intérêts
        cout << "\nAprès application des intérêts " << endl;
        compte1.setSolde(calculInteret(compte1.getSolde(), 2.5f));
        compte2.setSolde(calculInteret(compte2.getSolde(), 3.0f));
        
        compte1.afficher();
        compte2.afficher();
        
        // 5. Test de la portée et du destructeur
        cout << "\n Test de la portée " << endl;
        {
            Compte compte4(1004, 5000.0f, &client1);
            compte4.afficher();
            Compte::afficherNombreComptes();
        }
        
        cout << "\n=== État final ===" << endl;
        Compte::afficherNombreComptes();
        
    } catch (const exception& e) {
        cerr << "Erreur: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}