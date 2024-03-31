#!/usr/bin/env node
const readline = require('readline');
const { exec } = require('child_process');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  prompt: '$ ' // Set the prompt to '$ '
});

rl.prompt(); // Display the prompt

rl.on('line', (line) => {
  // Execute the command entered by the user
  exec(line, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error: ${error.message}`);
      return;
    }
    if (stderr) {
      console.error(`stderr: ${stderr}`);
      return;
    }
    console.log(stdout); // Print the output of the command
    rl.prompt(); // Display the prompt again
  });
}).on('close', () => {
  console.log('Exiting shell'); // Handle shell exit
  process.exit(0);
});

