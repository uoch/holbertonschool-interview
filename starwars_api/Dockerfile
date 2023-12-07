# Use an official Node.js 10 image as the base image
FROM node:10

# Install semistandard globally
RUN npm install semistandard --global

# Install request module in the working directory of the container
WORKDIR /app
RUN npm install request

# Copy your script into the container
COPY 0-starwars_characters.js /app

# Command to run your script
CMD ["node", "0-starwars_characters.js"]