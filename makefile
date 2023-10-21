Ass5: Party.o DemocraticParty.o RepublicanParty.o Politician.o Rpolitician.o Dpolitician.o Rsocialpolitician.o Rleaderpolitician.o Dsocialpolitician.o Dleaderpolitician.o Exception.o PoliticalSys.o main.o
	g++ Party.o DemocraticParty.o RepublicanParty.o Politician.o Rpolitician.o Dpolitician.o Rsocialpolitician.o Rleaderpolitician.o Dsocialpolitician.o Dleaderpolitician.o Exception.o PoliticalSys.o main.o -o Ass5


Party.o: Party.cpp Party.h Politician.h
	g++ -c Party.cpp Party.h Politician.h

DemocraticParty.o: DemocraticParty.cpp DemocraticParty.h Party.h Dleaderpolitician.h Dsocialpolitician.h
	g++ -c DemocraticParty.cpp DemocraticParty.h Party.h Dleaderpolitician.h Dsocialpolitician.h
	 
RepublicanParty.o: RepublicanParty.cpp RepublicanParty.h Party.h Rsocialpolitician.h Rleaderpolitician.h
	g++ -c RepublicanParty.cpp RepublicanParty.h Party.h Rsocialpolitician.h Rleaderpolitician.h

Politician.o: Politician.cpp Politician.h Party.h
	g++ -c Politician.cpp Politician.h Party.h
	
Rpolitician.o: Rpolitician.cpp Rpolitician.h
	g++ -c Rpolitician.cpp Rpolitician.h
	
Dpolitician.o: Dpolitician.cpp Dpolitician.h
	g++ -c Dpolitician.cpp Dpolitician.h
	
Rsocialpolitician.o: Rsocialpolitician.cpp Rsocialpolitician.h Rpolitician.h
	g++ -c Rsocialpolitician.cpp Rsocialpolitician.h Rpolitician.h
	
Rleaderpolitician.o: Rleaderpolitician.cpp Rleaderpolitician.h Rpolitician.h
	g++ -c Rleaderpolitician.cpp Rleaderpolitician.h Rpolitician.h
	
Dsocialpolitician.o: Dsocialpolitician.cpp Dsocialpolitician.h Dpolitician.h
	g++ -c Dsocialpolitician.cpp Dsocialpolitician.h Dpolitician.h
	
Dleaderpolitician.o: Dleaderpolitician.cpp Dleaderpolitician.h Dpolitician.h
	g++ -c Dleaderpolitician.cpp Dleaderpolitician.h Dpolitician.h
	
Exception.o: Exception.cpp Exception.h
	g++ -c Exception.cpp Exception.h

PoliticalSys.o: PoliticalSys.cpp PoliticalSys.h Party.h Politician.h DemocraticParty.h RepublicanParty.h Rpolitician.h Dpolitician.h Rsocialpolitician.h Rleaderpolitician.h Dsocialpolitician.h Dleaderpolitician.h Exception.h
	g++ -c PoliticalSys.cpp PoliticalSys.h Party.h Politician.h DemocraticParty.h RepublicanParty.h Rpolitician.h Dpolitician.h Rsocialpolitician.h Rleaderpolitician.h Dsocialpolitician.h Dleaderpolitician.h Exception.h
	
main.o: main.cpp PoliticalSys.h
	g++ -c main.cpp PoliticalSys.h
	
	
clean:
	rm -f *.o Ass5
