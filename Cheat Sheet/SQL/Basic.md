Resource: https://sqlzoo.net/wiki/SQL_Tutorial/zh

## 字符串相关
### 国家数据库
```sql
-- 找出所有國家,其名字都是 4 個字母的。
SELECT name FROM world
WHERE name LIKE '____'

-- 找出所有國家,其名字都有兩個字母 o,被另外兩個字母相隔着。
SELECT name FROM world
WHERE name LIKE '%o__o%'

-- 找出所有國家,其名字包括三個或以上的a。
SELECT name FROM world
WHERE name LIKE '%a%a%a%'

-- 找出所有國家,其名字以t作第二個字母。
SELECT name FROM world
WHERE name LIKE '_t%'
ORDER BY name

-- 顯示所有國家名字,其首都是國家名字加上”City”。
SELECT name
FROM world
WHERE capital=concat(name, ' City')

-- 找出所有首都和其國家名字,而首都要有國家名字中出現。
SELECT capital, name
FROM world
WHERE LOCATE(name,capital)>0

-- 找出所有首都和其國家名字,而首都是國家名字的延伸。
-- 你應顯示 Mexico City,因它比其國家名字 Mexico 長。
-- 你不應顯示 Luxembourg,因它的首都和國家名相是相同的。
SELECT name, capital
FROM world
WHERE LOCATE(name,capital) AND name != capital

-- In this example you remove all the 'a's from the name of each country. This happens because the string 'a' is replaced with .
SELECT name, REPLACE(name, 'a','')
FROM bbc

-- "Monaco-Ville"是合併國家名字 "Monaco" 和延伸詞"-Ville".
-- 顯示國家名字，及其延伸詞，如首都是國家名字的延伸。
-- 你可以使用SQL函數 REPLACE 或 MID.
SELECT name, REPLACE(capital,name,'')
FROM world
WHERE LOCATE(name,capital) AND name != capital

-- 顯示中國，澳大利亞，尼日利亞和法國的人口密度。
SELECT name, population/area
FROM world
WHERE name IN ('China', 'Nigeria', 'France', 'Australia')
```

### 诺贝尔奖数据库
```sql
-- Show the winners with first name John
SELECT winner
FROM nobel
WHERE MID(winner, 1, LOCATE(' ', winner)-1)='John ' -- or use: winner LIKE 'John %'

-- Show the year, subject, and name of physics winners for 1980 together with the chemistry winners for 1984.
SELECT yr, subject, winner
FROM nobel
WHERE (subject='physics' AND yr=1980) OR (subject='chemistry' AND yr= 1984)

-- Show the year, subject, and name of winners for 1980 excluding chemistry and medicine
SELECT yr, subject, winner
FROM nobel
WHERE yr=1980 AND subject!='chemistry' AND subject!='medicine'

-- Find all details of the prize won by EUGENE O'NEILL
-- You can't put a single quote in a quote string directly. You can use two single quotes within a quoted string.
SELECT yr, subject, winner
FROM nobel
WHERE winner LIKE 'EUGENE O''NEILL'

-- List the winners, year and subject where the winner starts with Sir. Show the the most recent first, then by name order.
SELECT winner, yr, subject
FROM nobel
WHERE winner LIKE 'Sir%'
ORDER BY yr DESC, winner

-- The expression subject IN ('chemistry','physics') can be used as a value - it will be 0 or 1.
-- Show the 1984 winners and subject ordered by subject and winner name; but list chemistry and physics last.
SELECT winner, subject
FROM nobel
WHERE yr=1984
ORDER BY subject IN ('physics','chemistry'),subject,winner
```

## SELECT in SELECT
```sql
-- List each country name where the population is larger than that of 'Russia'.
SELECT name FROM world
WHERE population >
    (SELECT population FROM world WHERE name='Russia')

-- Show the countries in Europe with a per capita GDP greater than 'United Kingdom'.
SELECT name FROM world
WHERE gdp/population >
    (SELECT gdp/population FROM world WHERE name='United Kingdom')
    AND continent='Europe'

-- List the name and continent of countries in the continents containing either Argentina or Australia. Order by name of the country.
SELECT name, continent FROM world
WHERE continent IN 
    (SELECT continent FROM world WHERE name='Argentina' OR name='Australia')
ORDER BY name

-- Germany (population 80 million) has the largest population of the countries in Europe. Austria (population 8.5 million) has 11% of the population of Germany.
-- Show the name and the population of each country in Europe. Show the population as a percentage of the population of Germany.
SELECT name, CONCAT(ROUND(100*population/(SELECT population FROM world WHERE name='Germany')), '%')
FROM world
WHERE continent='Europe'

-- We can use the word ALL to allow >= or > or < or <=to act over a list. For example, you can find the largest country in the world, by population with this query:
SELECT name
  FROM world
 WHERE population >= ALL(SELECT population
                           FROM world
                          WHERE population>0)

-- Which countries have a GDP greater than every country in Europe? [Give the name only.] (Some countries may have NULL gdp values)
SELECT name FROM world
WHERE gdp > ALL(SELECT gdp FROM world WHERE continent='Europe')

-- Find the largest country (by area) in each continent, show the continent, the name and the area:
SELECT continent, name, area FROM world x
WHERE area >= ALL(SELECT area FROM world y WHERE y.continent=x.continent)

-- List each continent and the name of the country that comes first alphabetically.
SELECT continent, name FROM world x
WHERE name <= ALL(SELECT name FROM world y WHERE x.continent=y.continent)

-- Some countries have populations more than three times that of all of their neighbours (in the same continent). Give the countries and continents.
SELECT name, continent FROM world x
WHERE population > ALL(SELECT population*3 FROM world y WHERE x.continent=y.continent AND x.name!=y.name)

-- WHERE and GROUP BY. The WHERE filter takes place before the aggregating function. For each relevant continent show the number of countries that has a population of at least 200000000.
SELECT continent, COUNT(name)
FROM world
WHERE population>200000000
GROUP BY continent

-- GROUP BY and HAVING. The HAVING clause is tested after the GROUP BY. You can test the aggregated values with a HAVING clause. Show the total population of those continents with a total population of at least half a billion.
SELECT continent, SUM(population)
FROM world
GROUP BY continent
HAVING SUM(population)>500000000
```

## Join用法
link: https://sqlzoo.net/wiki/The_JOIN_operation
```sql
-- Show the team1, team2 and player for every goal scored by a player called Mario player LIKE 'Mario%'
SELECT team1, team2, player
FROM game JOIN goal ON (id=matchid)
WHERE player LIKE 'Mario%'

-- List the dates of the matches and the name of the team in which 'Fernando Santos' was the team1 coach.
SELECT mdate, teamname
FROM game JOIN eteam ON (eteam.id=team1)
WHERE coach='Fernando Santos'

-- 13. List every match with the goals scored by each team as shown. This will use "CASE WHEN" which has not been explained in any previous exercises.
SELECT mdate, team1, SUM(CASE WHEN teamid=team1 THEN 1 ELSE 0 END) as score1, team2, SUM(CASE WHEN teamid=team2 THEN 1 ELSE 0 END) as score2
FROM game LEFT JOIN goal ON id=matchid
GROUP BY id
ORDER BY mdate, matchid, team1, team2
```

## Join用法part 2
link: https://sqlzoo.net/wiki/More_JOIN_operations
```sql
-- Which were the busiest years for 'Rock Hudson', show the year and the number of movies he made each year for any year in which he made more than 2 movies.
SELECT yr,COUNT(title) FROM
  movie JOIN casting ON movie.id=movieid
        JOIN actor   ON actorid=actor.id
WHERE name='Rock Hudson'
GROUP BY yr
HAVING COUNT(title) > 2

-- 12. List the film title and the leading actor for all of the films 'Julie Andrews' played in.
SELECT title, name
FROM movie JOIN casting ON movieid=movie.id JOIN actor ON actorid=actor.id
WHERE movie.id IN(SELECT movieid FROM casting JOIN actor ON actorid=id WHERE name='Julie Andrews') AND ord=1

-- 13. Obtain a list, in alphabetical order, of actors who've had at least 15 starring roles.
SELECT name
FROM actor
WHERE id IN (SELECT actorid FROM casting WHERE ord=1 GROUP BY actorid HAVING COUNT(actorid)>=15)
ORDER BY name

-- 14. List the films released in the year 1978 ordered by the number of actors in the cast, then by title.
SELECT title, COUNT(actorid)
FROM movie JOIN casting ON movieid=id
WHERE yr=1978
GROUP BY movieid
ORDER BY COUNT(actorid) DESC, title

-- 15. List all the people who have worked with 'Art Garfunkel'.
SELECT DISTINCT name
FROM casting JOIN actor ON actorid=id
WHERE movieid IN(SELECT movieid FROM casting JOIN actor ON actorid=id WHERE name='Art Garfunkel') AND actorid!=(SELECT id FROM actor WHERE name='Art Garfunkel')
```

## NULL, INNER JOIN, LEFT JOIN, RIGHT JOIN
```sql
-- 1. List the teachers who have NULL for their department.
SELECT name
FROM teacher
WHERE dept IS NULL

-- 5. Use COALESCE to print the mobile number. Use the number '07986 444 2266' if there is no number given. Show teacher name and mobile number or '07986 444 2266'
SELECT name, COALESCE(mobile, '07986 444 2266')
FROM teacher
```

## Self JOIN
```sql
-- 6. The query shown is similar to the previous one, however by joining two copies of the stops table we can refer to stops by name rather than by number. Change the query so that the services between 'Craiglockhart' and 'London Road' are shown.
SELECT a.company, a.num, stopa.name, stopb.name
FROM route a JOIN route b ON
  (a.company=b.company AND a.num=b.num)
  JOIN stops stopa ON (a.stop=stopa.id)
  JOIN stops stopb ON (b.stop=stopb.id)
WHERE stopa.name='Craiglockhart' AND stopb.name='London Road'

-- 8. Give a list of the services which connect the stops 'Craiglockhart' and 'Tollcross'
SELECT a.company, a.num
FROM route a JOIN route b ON (a.company=b.company AND a.num=b.num) JOIN stops sa ON (a.stop=sa.id) JOIN stops sb ON (b.stop=sb.id)
WHERE sa.name='Craiglockhart' AND sb.name='Tollcross'

-- 9. Give a distinct list of the stops which may be reached from 'Craiglockhart' by taking one bus, including 'Craiglockhart' itself, offered by the LRT company. Include the company and bus no. of the relevant services.
SELECT DISTINCT sb.name, b.company, b.num
FROM route a JOIN route b ON (a.company=b.company AND a.num=b.num) JOIN stops sa ON (a.stop=sa.id) JOIN stops sb ON (b.stop=sb.id)
WHERE a.company='LRT' AND sa.name='Craiglockhart'
```

## Case WHEN
CASE allows you to return different values under different conditions.
If there no conditions match (and there is not ELSE) then NULL is returned.
```sql
CASE WHEN condition1 THEN value1 
     WHEN condition2 THEN value2  
     ELSE def_value 
END 


SELECT name, population
      , CASE WHEN population<1000000 
            THEN 'small'
            WHEN population<10000000 
            THEN 'medium'
            ELSE 'large'
        END
FROM bbc
```