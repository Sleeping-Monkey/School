<?php

include("data.php");

if (isset($_GET['id']))
{
  $id = $_GET['id'];
  print_r($_GET);
  $query = "UPDATE phones SET ";
  $gquery = "INSERT matches (human_id, group_id) VALUES ";
  foreach ($_GET as $key => $val)
  {
    if ($val !== '' && $key !== 'id' && !is_array($val))
    {
      $query .= $key."="."'".$val."'".", ";
    }
    else if (is_array($val))
    {
      foreach ($val as $grp)
      {
        $gquery .= '('.($id).','.$grp.'),';
      }
    }
  }
  $query = chop($query, ', ');
  $gquery = chop($gquery, ', ');
  $query.=" WHERE id=".($id);
  echo $query;
  echo $gquery;
  exec_query($query);
  exec_query($gquery);
}

else
{
  $query = "INSERT INTO phones (";
  $gquery = "INSERT INTO matches (human_id, group_id) VALUES";

  foreach($_GET as $key => $val )
  {
    if (!is_array($val))
    {
      $query.=$key.",";
    }
  }
  $query = chop($query, ',');
  $query .= ") VALUES (";
  foreach($_GET as $val)
  {
    if (!is_array($val))
    {
      $query.="'".$val."'".",";
    }
  }
  $query = chop($query, ',');
  $query .= ');' ;
  echo $query;
  $id = exec_query($query);
#updating groups
  foreach($_GET as $key => $val )
  {
    if (is_array($val))
    {
     foreach ($val as $grp)
      {
        $gquery .= '('.($id).','.$grp.'),';
      }
    }
  }
  $gquery = chop($gquery, ', ');
  echo $gquery;
  exec_query($gquery);
}
?>
<html>
  <head>
    <meta charset="atf-8">
  </head>
  <body>  
    <b><a href="printer.php">Вернуться к списку!</a></b>
  </body>
</html>