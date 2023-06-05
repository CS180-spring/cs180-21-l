# Using the GUI

## Starting the GUI

```bash
cd gui
yarn start

```

to end the process is the same as ending a Node.js process → Ctrl + C

## Working with the GUI

We are using Electron.js as the desktop system with React.js as our framework. as for UI, we are using Segment’s Evergreen Framework.

[Evergreen Framework Components](https://evergreen.segment.com/components)

Electron.js uses a main and render process to generate our application.

- Main Process
    - Controls the window and display of the application
    - It is an event-driven process which means if you want to change any functionality of the window it is control via the main process
    - This process is in the `/src` folder the file is called `main.js`
- Render Process
    - Kinda like the Front-End application
    - We are using React here

Currently we have set the `nodeIntegration: true` in the `main.js` file. This means that the render and react have access to Node.js modules.

## Important Files

- `/src/main.js`
    - the main process
- `/src/app.jsx`
    - entry to the react application
- `/src/pages/hello.jsx`
    - sample page