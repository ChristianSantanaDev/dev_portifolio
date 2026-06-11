<?php
require "conexao.php";

$msg = "";

    if($_SERVER['REQUEST_METHOD'] == 'POST'){
        // validação geral
        if(empty($_POST['name']) || empty($_POST['email']) || empty($_POST['password'])){
            $msg = 'Preencha todos os dados';    
        } else {
            $nome = trim(htmlspecialchars($_POST['name']));
            $email = trim(htmlspecialchars($_POST['email']));
            $senha_plana = trim($_POST['password']);

            $senha_hash = password_hash($senha_plana, PASSWORD_DEFAULT);

            $stmt = mysqli_prepare($conn, "INSERT INTO usuarios (nome, email, senha) VALUES (?, ?, ?)");

            mysqli_stmt_bind_param($stmt, "sss", $nome, $email, $senha_hash);

            if(mysqli_stmt_execute($stmt)){
                $msg = "Usuario cadastrado com sucesso!";
            } else {
                $msg = "Erro: " . mysqli_stmt_error($stmt);
            }

            mysqli_stmt_close($stmt);
            mysqli_close($conn);

            
        }
    }
?>


<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="" method="post">
        nome: <input type="text" maxlength="255" name="name" required value="">
        email: <input type="email" maxlength="255" name="email" required value="">
        senha: <input type="password" maxlength="255" name="password" required value="">
        <button type="submit">Enviar</button>
    </form>
    <?php
        if(isset($_POST['name'])){
            echo $msg;
        }
    ?>
</body>
</html>