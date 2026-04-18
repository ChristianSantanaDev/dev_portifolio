use escola;
/*• Comando SQL que liste as matérias cursadas pelo aluno com nome iniciado com " xxxx
". */
select
materia.*
from
aluno, MatriculadoEm, materia
where
aluno.IdAluno = MatriculadoEm.IdAluno
and
MatriculadoEm.IdMateria = materia.IdMateria
and
aluno.NomeAluno like 'Pedro%';

use escola;
/*• Comando SQL que liste os anos e os nomes das matérias que um determinado aluno
cursou e está cursando. */
select
MatriculadoEm.ano, materia.materia
from
aluno, MatriculadoEm, materia
where
aluno.IdAluno = MatriculadoEm.IdAluno
and
MatriculadoEm.IdMateria = materia.IdMateria
and
aluno.IdAluno = 1;


use escola;
/*• Comando SQL para uma consulta que você considera importante.*/
/*Meu comando:
Comando SQL pra mostrar os dados de uma materia que um aluno cursa ou cursou:
Mostrar:
Nome do Aluno, Nome do Professor, Nome da materia, media, falta e situacao
*/
select
aluno.NomeAluno, professor.NomeProfessor, materia.materia,
MatriculadoEm.media, MatriculadoEm.faltas, MatriculadoEm.situacao
from
aluno, MatriculadoEm, materia, professor
where
aluno.IdAluno = MatriculadoEm.IdAluno
and
MatriculadoEm.IdMateria = materia.IdMateria
and
materia.IdProfessor = professor.IdProfessor
and
aluno.IdAluno = 1;
