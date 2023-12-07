#!/usr/bin/node

const request = require('request');
const id = process.argv[2];

if (!id) {
    console.error('Please provide a film ID.');
    process.exit(1);
}

request('https://swapi-api.hbtn.io/api/films/' + id, function (error, response, body) {
    if (error) {
        console.error(error);
    }
    const parsed = JSON.parse(body);
    const characters = parsed.characters;
    for (let i = 0; i < characters.length; i++) {
        request(characters[i], function (error, response, body) {
            if (error) {
                console.error(error);
            }
            const parsed = JSON.parse(body);
            console.log(parsed.name);
        });
    }
});
