#!/bin/env python3

# programme de résolution du problème du voyaguer de commerce
# par l'algorithme du recuit simulé

# importation des librairies
import numpy as np
from matplotlib.pyplot import *


# paramètres de l'algorithme de recuit simulé
T0 = 10.0
Tmin = 1e-2
tau = 1e4

# definition d'une classe ville pour representer un objet ville
class Coordonnee:
    def __init__(self, lat: float, lon: float) -> None:
        self.lat = lat
        self.lon = lon

    def __str__(self) -> str:
        return f"coord = (lat={self.lat}; lon={self.lon})"    

class Ville:
    def __init__(self, nom: str, lat: float, lon: float) -> None:
        self.nom = nom
        self.lat = lat
        self.lon = lon

    def __str__(self) -> str:
        return f"nom = {self.nom}, coord = (lat={self.lat}; lon={self.lon})"


# fonction utilitaire
def deg2rad(degree: float) -> float:
    return (degree * np.pi)/180

def distance(x : Ville, y: Ville) -> float:
    latx = deg2rad(x.lat)
    laty = deg2rad(y.lat)
    lonx = deg2rad(x.lon)
    lony = deg2rad(y.lon)

    return R * np.arccos((np.cos(latx)*np.cos(laty)*np.cos(lony - lonx)) + np.sin(latx)*np.sin(laty))



# fonction de lecture des villes à partir du fichier texte contenant
# les villes
def lectureVille(filename: str) -> list:
    villes = []
    with open(filename) as f:
        head = f.readline();
        lines = f.readlines();
        for line in lines:
            l = line.split()
            v = Ville(l[0], l[1], l[2])
            villes.append(v)
    return villes

# fonction de calcul de l'énergie du système, égale à la distance totale
# du trajet selon le chemin courant
def EnergieTotale():
    global trajet
    energie = 0.0
    coord = np.c_[x[trajet],y[trajet]]
    energie = np.sum(np.sqrt(np.sum((coord - np.roll(coord,-1,axis=0))**2,axis=1)))
    return energie




# fonction de fluctuation autour de l'état "thermique" du système
def Fluctuation(i,j):
    global trajet
    Min = min(i,j)
    Max = max(i,j)
    trajet[Min:Max] = trajet[Min:Max].copy()[::-1]
    return

# fonction d'implémentation de l'algorithme de Metropolis
def Metropolis(E1,E2):
    global T
    if E1 <= E2:
        E2 = E1  # énergie du nouvel état = énergie système
    else:
        dE = E1-E2
        if np.random.uniform() > np.exp(-dE/T): # la fluctuation est retenue avec  
            Fluctuation(i,j)              # la proba p. sinon retour trajet antérieur
        else:
            E2 = E1 # la fluctuation est retenue 
    return E2
    
# initialisation des listes d'historique
Henergie = []     # énergie
Htemps = []       # temps
HT = []           # température

# répartition aléatoire des N villes sur le plan [0..1,0..1]
# x1 = np.random.uniform(size=N)
# y2 = np.random.uniform(size=N)

#On définit le centre de la france
lat0 = 46.36
lon0 = 2.29

R = 6371.009 #rayon de la terre

#On récupère les villes du fichier villes.txt
villes = lectureVille("villes.txt")
N = len(villes)    # nombre de villes

x = np.empty(0)
y = np.empty(0)
for v in villes:
    x1 = R*(deg2rad(float(v.lon))-deg2rad(lon0))*np.cos(deg2rad(lat0))
    #print (x1)
    y1 =  R*(deg2rad(float(v.lat))-deg2rad(lat0))
    #print(y1)
    x = np.append(x, x1)
    y = np.append(y, y1)
    

# défintion du trajet initial : ordre croissant des villes
trajet = np.arange(N)
trajet_init = trajet.copy()

# calcul de l'énergie initiale du système (la distance initiale � minimiser)
Ec = EnergieTotale()

# boucle principale de l'algorithme de recuit simulé
t = 0
T = T0
while T > Tmin:
    # choix de deux villes diff�rentes au hasard
    i = np.random.randint(0,N)
    j = np.random.randint(0,N)
    if i == j: continue
        
    # création de la fluctuation et mesure de l'énergie
    Fluctuation(i,j) 
    Ef = EnergieTotale()   
    Ec = Metropolis(Ef,Ec)
    
    # application de la loi de refroidissement    
    t += 1
    T = T0*np.exp(-t/tau)  

    # historisation des données
    if t % 10 == 0:
        Henergie.append(Ec)
        Htemps.append(t)
        HT.append(T)

print(f"la distance du trajet minimal est {Henergie[-1]}")
print(f"qui correspond au trajet: {', '.join(villes[t].nom for t in trajet)}")

# fin de boucle - affichage des états finaux
# affichage du réseau
fig1 = figure(1)
subplot(1,2,1)
xticks([])
yticks([])
plot(x[trajet_init],y[trajet_init],'k')
plot([x[trajet_init[-1]], x[trajet_init[0]]],[y[trajet_init[-1]], \
      y[trajet_init[0]]],'k')
plot(x,y,'ro')
title('Trajet initial')

subplot(1,2,2)
xticks([])
yticks([])
plot(x[trajet],y[trajet],'k')
plot([x[trajet[-1]], x[trajet[0]]],[y[trajet[-1]], y[trajet[0]]],'k')
plot(x,y,'ro')
title('Trajet optimise')
show()

# affichage des courbes d'évolution
fig2 = figure(2)
subplot(1,2,1)
semilogy(Htemps, Henergie)
title("Evolution de l'energie totale du systeme")
xlabel('Temps')
ylabel('Energie')
subplot(1,2,2)
semilogy(Htemps, HT)
title('Evolution de la temperature du systeme')
xlabel('Temps')
ylabel('Temperature')
show()