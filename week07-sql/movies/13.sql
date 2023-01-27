SELECT DISTINCT(people.name)
FROM people
WHERE people.id IN (SELECT stars.person_id
    FROM stars
    WHERE stars.movie_id IN (SELECT stars.movie_id
    FROM stars
    WHERE person_id IN (SELECT people.id
    FROM people
    WHERE name = "Kevin Bacon"
        AND birth = 1958)))
    AND people.name != "Kevin Bacon"
ORDER BY people.name;