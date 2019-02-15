<!DOCTYPE html >
<html>
  <head>
    <meta charset = 'atf-8' />
    <title>Профиль человека</title>
  </head>
  <body>
  <?php 
   include("data.php");

   if (isset($_GET['id']))
   {

     echo "<h2>Текущие данные</h2>" ;
     echo "<table border = 1>";
     echo "<tbody>" ;

     $human = get_human($_GET['id'])[0];
     foreach($human as $key => $val)
     {
       
       echo "<tr>\n";
       echo "<td>".$key."</td>"."<td>".$val."</td>\n";
       echo "</tr>\n";
     }

      echo "</tbody>";
      echo "</table>";
    }
    ?>
    <h2>Изменение</h2>
    <form action="apply_changes.php" method="GET">';
      <?php
      if (isset ($_GET['id'])) {
        echo '<input type="hidden" name="id" value = '.$_GET['id'].' />';
      }
      ?>
      Фамилия:<input type="text" name = "Surname" /> <br />
      Имя:<input type="text" name = "Name" /> <br />
      Телефон:<input type="text" name = "Phone" /> <br />
      <?php
        $groups = get_groups();
        foreach($groups as $group)
        {
            echo '<input type="checkbox" name = "groups[]" value="'.$group['id'].'" />';
            echo $group['name']."<br />". "\n";
        }
      ?>
      <input type="submit" value="Сохранить">
    </form>
    <form action="remove.php" method='GET'>
      <input type="submit" value="Удалить!">
    </form>
  </body>
</html>