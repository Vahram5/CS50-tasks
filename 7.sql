SELECT AVG(energy) FROM songs
WHERE songs.artist_id IN (SELECT id FROM artists WHERE name LIKE "Drake")