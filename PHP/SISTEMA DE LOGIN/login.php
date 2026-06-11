<?php 
    session_start();
    
    require "conexao.php";

    $msg = "";

    if(isset($_SESSION['usuario_id'])){
        header("Location: dashboard.php");
        exit;
    }

    if($_SERVER["REQUEST_METHOD"] === "POST"){
        $email = $_POST["email"] ?? "";
        $senha = $_POST["password"] ?? "";

        if(empty($email) || empty($senha)){
            $msg = "Preencha todos os campos!";
        } else {
            $stmt = mysqli_prepare($conn, "SELECT id, nome, senha FROM usuarios WHERE email = ?");
            mysqli_stmt_bind_param($stmt, "s", $email);
            mysqli_stmt_execute($stmt);
            $result = mysqli_stmt_get_result($stmt);

            if($usuario = mysqli_fetch_assoc($result)){

                if(password_verify($senha, $usuario["senha"])){
                    //logar
                    session_regenerate_id(true);

                    $_SESSION["usuario_id"] = $usuario["id"];
                    $_SESSION["usuario_nome"] = $usuario["nome"];

                    mysqli_stmt_close($stmt);
                    mysqli_close($conn);

                    header("Location: dashboard.php");
                    exit;
                }
            }
            $msg = "Email ou senha invalidos.";
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
        email:<input type="email" maxlength="255" required name="email">
        senha:<input type="password" maxlength="255" required name="password">
        <button type="submit">Enviar</button>
    </form>
    <?=$msg?>
</body>
</html>