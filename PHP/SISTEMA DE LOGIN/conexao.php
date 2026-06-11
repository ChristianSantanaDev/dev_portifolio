<?php
require_once 'config.php';

// Estabelece a conexão
$conn = mysqli_connect($host, $user, $pass, $dbname);

// Verifica se houve erro
if (mysqli_connect_error()) {
    die("Erro de conexão: " . mysqli_connect_error());
}
?>

