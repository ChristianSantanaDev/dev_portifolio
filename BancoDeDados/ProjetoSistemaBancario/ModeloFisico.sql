/*MySql (Criação do banco de dados):*/

create database Banco;
use Banco;
create table cliente (CPF varchar(11) primary key,
RG int,
Nome varchar(50),
Endereco varchar(50),
telefone varchar(15),
EstadoCivil varchar(15)
);
create table agencia (CodAge int primary key,
nome varchar(50),
endereco varchar(50),
NomeGerente varchar(50)
);
create table conta (NumConta int primary key,
saldo decimal(10,2),
CPF varchar(11),
CodAge int,
constraint fk_cliente
foreign key (CPF) references cliente(CPF),
constraint fk_agencia
foreign key (CodAge) references agencia(CodAge)
);
create table movimentacao(tipo varchar(10),
quantia decimal(10,2),
data date,
hora time,
NumConta int,
IdMov int primary key,
constraint fk_conta
foreign key (NumConta) references conta(NumConta)
);