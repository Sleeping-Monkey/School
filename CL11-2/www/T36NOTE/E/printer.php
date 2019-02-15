<?php

function print_headers($a)
{
  echo "<tr>\n";
  if (isset($a[0]))
  {
    $val = $a[0];
    foreach($val as $key => $value)
    {
      echo "<th>".$key."</th>\n";
    }
    echo "</tr>\n";
  }
}
function print_data($a)
{
  foreach($a as $human)
  {
    echo "<tr>\n";
    foreach ($human as $val)
    {
      echo "<td>";
      echo $val;
      echo "</td>";
    }
    echo "<td>";
    echo "<a href = 'human.php?id=".$human['id']."'>";
    echo "Edit\n";
    echo "</a>";
    echo "</td>";
    echo "</tr>\n";
  }
}

function filter()
{
  $query = "
  SELECT phones.id, phones.name , phones.surname, phone ,GROUP_CONCAT(groups.name SEPARATOR ',') as 'group' 
  FROM phones 
  JOIN matches 
  ON phones.id = human_id
  JOIN groups
  ON groups.id = group_id
  WHERE ";
  foreach($_GET as $key => $val)
  {
    $key = preg_replace('/_/', '.', $key);
    $query .= $key.' LIKE "%'.$val.'%"'.' AND ';
  }
  $query .= 'TRUE GROUP BY phones.name ORDER BY id ';

  $filtered_humans = exec_tabl_query($query);
#  print_r($filtered_humans);
  return $filtered_humans;
}


?>

<!DOCTYPE html >
<html>
  <head>
    <meta charset = 'atf-8' />
    <title>Записная книга</title>
  </head>
  <body>
    <?php
      include('data.php');
#      print_r($_GET);
    ?>
    <form action="printer.php" method="GET"> 
      Фамилия:<input type="text" name = "phones.surname"><br />
      Имя:<input type="text" name = "phones.name"><br />
      Группы:
      <select name="groups.id">
      <?php
        $query = 'SELECT * FROM groups';
        $groups = exec_tabl_query($query);
        foreach ($groups as $group)
        {
          echo '<option value="'.$group['id'].'">'.$group['name'].'</option>';
        }
      ?>
      </select>
      <input type="submit" value="Фильтровать">
    </form>
    <br />
      <table border = 1>
       <tbody>
         <?php
           $humans = filter();
           print_headers($humans);
           print_data($humans);
         ?>
     </tbody>
    </table>
    <br />
    <form action="human.php" method="GET">
      <input type="submit" value="Добавить">
    </form>
  </body>
</html>