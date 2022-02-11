# Mécanisme d'appel système

Lorsqu'un utilisateur effectue un appel système, cela se traduit par une instruction `syscall` dans le code MIPS. Quand le système lit cette instruction, cela génère une exception qui dépend du type de l'appel système; cette exception est gérée dans le fichier exception.cc, où les opérations qui y correspondent sont effectuées (création d'une sémaphore, d'un thread etc..)

# Gestion de threads et de processus

1. Lors d'un changement de contexte, il est nécessaire de sauvegarder l'état des registres du processeur ainsi que l'état du simulateur virtuel.
2. Les threads prêts à s'exécuter sont dans la variable `readyList` du `Scheduler`. Le thread courant est dans la variable `g_current_thread`.
3. La variable `g_alive` liste l'intégralité des threads qui sont "en vie", y compris ceux en attente (par exemple d'une sémaphore), tandis que `readyList` comprend uniquement les threads qui peuvent continuer leur exécution sans bloquage immédiat.
4. La gestion des listes ne se charge pas d'allouer ou de désallouer de la mémoire, parce qu'on veut pouvoir continuer à manipuler des objets même en les retirant de certaines listes.
5. Quand un thread se bloque sur un sémpahore il est placée dans une file d'attente liée à ce sémaphore, ce qui permet au Scheduler de savoir lorsqu'il peut le réveiller.
6. Il faut désactiver les interruptions pour effectuer ses opérations, puis les réactiver une fois qu'on a fini.
7. La méthode `SwitchTo` provoque une changement de contexte vers le thread passé en paramètre, et donc relance son exécution. `thread_context` contient les registres utilisateur du CPU simulé, `simulator_context` contient le stackpointer et la taille de la stack pour pouvoir reprendre l'exécution. Les méthodes save et restore sauvegardent et restaurent l'état d'un thread et du simulateur lors d'un changement de contexte.
8. Les objets étant manipulés via registres par le noyau, ils ne peuvent pas être type-checkés par le système de type C/C++, il faut donc rajouter un champ à tester pour pouvoir vérifier que le noyau reçoit le bon type d'objet.

# Environnement de développement

1. Pour développer des programmes, Nachos fourni une version réduite de la libraire standard C, qui sont compilables pour obtenir du code MIPS exécutable par le noyau (au format ELF). Des règles de compilation sont contenues dans le Makefile. L'exécutable résultat permet à travers des options, d'afficher des messages de débug (-d), d'exécuter le code pas à pas en affichant tout le contexte d'exécution (-s) ou d'exécuter un programme spécifié (-x). Cet exécutable peut avoir des caractéristiques différentes selon le fichier de configuration spécifié.
2. On peut utiliser GDB pour développer Nachos car il s'agit d'un OS virtuel qui tourne sur du code C++.
3. On ne peut pas en revanche utiliser GDB pour les programmes utilisateur, puisque le code est compilé spécifiquement pour être exécutable par Nachos. On peut plutôt utiliser l'option -s pour lancer une exécution pas à pas, qui se rapproche d'un outil comme GDB.