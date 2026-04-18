create database escola;
use escola;
create table aluno (IdAluno int primary key,
NomeAluno varchar(50) not null
);
create table professor (IdProfessor int primary key,
NomeProfessor varchar(50)
);
create table materia (IdMateria int primary key,
materia varchar(30),
IdProfessor int,
constraint fk_professor
foreign key (IdProfessor) references professor(IdProfessor)
);
create table MatriculadoEm (ano int,
faltas int,
media decimal(4,1),
situacao enum('APROVADO', 'RECUPERACAO', 'DEPENDENCIA'),
IdAluno int,
IdMateria int,
constraint fk_aluno
foreign key (IdAluno) references aluno(IdAluno),
constraint fk_materia
foreign key (IdMateria) references materia(IdMateria),
primary key(IdAluno, IdMateria, ano) /*pro aluno poder fazer a mesma materia em anos
diferentes*/
);
