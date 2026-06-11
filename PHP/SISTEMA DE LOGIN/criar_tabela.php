<?php
    require "conexao.php";

    $sql = "CREATE TABLE IF NOT EXISTS usuarios (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    senha VARCHAR(255) NOT NULL,
    data_cadastro TIMESTAMP DEFAULT CURRENT_TIMESTAMP
    )";

    mysqli_query($conn, $sql);
    echo "Tabela usuarios pronta!";

    mysqli_close($conn);

?>