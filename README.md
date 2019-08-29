# C
Questo repository contiene vari progetti relativi ai laboratori del corso: *Programmazione distribuita I (2018/2019)* tenuto presso il [Politecnico di Torino](https://www.polito.it/). Ogni sotto cartella rappresenta un progetto a se stante. Per l'utilizzo e il test dei sorgenti è stata configurata un'apposita immagine docker

## Creazione di un progetto
Per creare un progetto in maniera automatica è possibile utilizzare lo script `crapp` presente all'interno del repository. Per utilizzarlo:
1. Posizionarsi nella cartella C 
2. Eseguire uno dei seguenti comandi:
	1. Per creare un applicativo server: ./crapp `<project-name> -s [-tcp|-udp]` attualmente  		   l'unico protocollo supportato è tcp quindi il comando diventa: `<project-name> -s -tcp`
	2. Per creare un applicativo client: ./crapp `<project-name> -c`
> **NB:** lo script contiene comandi `sudo` quindi va eseguito su macchina Linux, assicurarsi che il file abbia i permessi `rwx`

## Struttura di un progetto
Per inizializzare un nuovo progetto creare all'interno della cartella del ropository una nuova directory, di conseguenza creare 
al suo interno le seguenti subdirectory:
* **src:** cartella che contiene tutti i sorgenti dell'applicazione, importante ricordare che non devono essere presenti due main, quest
potrebbe capitare qualora ci fossero dei test.
* **headers:** conterrà tutti i file di header locali, se invece si volesse definire un header globale, condivisibile quindi con
altri progetti, esso dovrà essere inserito nella cartella `global-headers` presente all'interno del repository. Questa cartella per ora
prevede solamente file con estensione `.h` di conseguenza non contiene al suo interno la definizione dei metodi. Per poter utilizzare i
file di libreria in esso presenti copiare i file con estensione `.c` all'interno della cartella `src` di cui sopra.
* **test:** cartella per ora inutilizzata, tenuta per avere una struttura dei progetti estensibile e simile a quella utilizza per i progetti
in C++ 
* **local-storage:** cartella che rappresenta un local storage per l'applicativo, qui vanno inseriti eventuali file di configurazione e file necessari per il funzionamento dell'applicazione che non siano sorgenti. Nel repository non stati inseriti file di grosse dimensioni in quanto GitHub limita le dimensioni dei file sui quali viene fatto push. Un comando utile a creare rapidamente dei grossi file in linux è il seguente: `fallocate -l 1G <filename>`, l'opzione `-l` sta per length e a seguire troviamo la dimensione del file. Per ulteriori informazioni sul comando: [fallocate](http://man7.org/linux/man-pages/man1/fallocate.1.html). Se si clona il progetto e si volesse testare gli applicativi con file di grosse dimensioni basta apporre *large* al nome del file, es: `fallocate -l 1G large-iso.iso`, è stata inserita infatti un'apposita regola nel file `.gitignore` per risolvere il problema.

> **NB:** è importante specificare l'estensione del file altrimenti la regola nel file fallisce.

## Utilizzare app con Docker 
Per poter utilizzare l'applicazione con docker occore seguire i seguenti passaggi:
1. Installare [Docker CE](https://docs.docker.com/install/linux/docker-ce/ubuntu/) se non precedentemente fatto
2. Posizionarsi nella cartella C 
3. Eseguire uno dei seguenti comandi:
	1. Per lanciare un server: ./app-dock `<project-name> -s <param1> <param2> ... <paramN>`
	2. Per lanciare un client: ./app-dock `<project-name> -c <param1> <param2> ... <paramN>`
> **NB:** lo script contiene comandi `sudo` quindi va eseguito su macchina Linux, assicurarsi che il file abbia i permessi `rwx`

## Configurazione di rete
Ogni applicativo risiede all'interno di un container che espone la porta 1500. Il binding della porta lato host viene fatto in due modi
differenti a seconda che l'applicativo ospiti un client o un server. Se l'applicazione ospita un server il binding viene effettuato sulla
porta 3000, non è possibile quindi al momento avere diversi server che lavorano in parallelo. Per quanto riguarda invece un client la porta
di binding viene scelta in maniera random, questa infatti non ha bisogno di essere nota a priori in quanto le connessioni vengono aperte dai
client. In definitiva un applicativo client per contattare un server dovrà specificare due parametri: `<server address> 3000`
> **NB:** se si adopera docker su macchina linux i container sono raggiungibili tramite l'indirizzo di localhost: `127.0.0.1` 

## Utilizzare app in locale
Per poter utilizzare l'applicazione in locale occore seguire i seguenti passaggi:
1. Installare `gcc` 
2. Posizionarsi nella cartella C
3. Eseguire uno dei seguenti comandi:
	1. Per lanciare un server: ./app-local `<project-name> -s <param1> <param2> ... <paramN>`
	2. Per lanciare un client: ./app-local `<project-name> -c <param1> <param2> ... <paramN>`
> **NB:** lo script contiene comandi `sudo` quindi va eseguito su macchina Linux, assicurarsi che il file abbia i permessi `rwx`
