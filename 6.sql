SELECT songs.name FROM songs
JOIN artists On artists.id = songs.artist_id
WHERE artists.name LIKE "Post Malone";