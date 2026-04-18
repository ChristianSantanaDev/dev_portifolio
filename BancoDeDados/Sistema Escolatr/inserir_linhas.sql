use escola;
/*• Comandos SQL que insiram 3 linhas em cada tabela.*/
INSERT INTO aluno (IdAluno, NomeAluno)
VALUES
(1, 'Pedro Rodrigues'),
(2, 'Maria Silva'),
(3, 'João Souza');
INSERT INTO professor (IdProfessor, NomeProfessor)
VALUES
(1, 'Julio Souza'),
(2, 'Ana Lima'),
(3, 'Carlos Mendes');
INSERT INTO materia (IdMateria, materia, IdProfessor)
VALUES
(1, 'Desenvolvimento Web', 1),
(2, 'Banco de Dados', 2),
(3, 'Algoritmos', 3);
INSERT INTO MatriculadoEm (ano, faltas, media, situacao, IdAluno, IdMateria)
VALUES
(2026, 2, 70.1, 'APROVADO', 1, 1),
(2026, 5, 55.0, 'RECUPERACAO', 2, 2),
(2026, 10, 40.0, 'DEPENDENCIA', 3, 3);
