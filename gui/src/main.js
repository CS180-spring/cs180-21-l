const { app, BrowserWindow, ipcMain } = require("electron");
const path = require("path");
const { spawn } = require("child_process");
const chokidar = require("chokidar");
// Handle creating/removing shortcuts on Windows when installing/uninstalling.
if (require("electron-squirrel-startup")) {
  app.quit();
}

const createWindow = () => {
  // Create the browser window.
  const mainWindow = new BrowserWindow({
    width: 1400,
    height: 950,
    minWidth: 800,
    minHeight: 600,
    webPreferences: {
      preload: MAIN_WINDOW_PRELOAD_WEBPACK_ENTRY,
      nodeIntegration: true,
    },
  });
  ipcMain.on("set-title", (event, title) => {
    const webContents = event.sender;
    const win = BrowserWindow.fromWebContents(webContents);
    console.log("setting title to", title);
    win.setTitle(title);
  });
  ipcMain.on("open-terminal", (event) => {
    // get the path to the current directory
    const codeDirectory = path.join(__dirname, "..", "..", "..");
    console.log("opening terminal at path", codeDirectory);
    //check if a terminal is already open
    //if it is, then open a new tab in the existing terminal
    //if it isn't, then open a new terminal

    let openTerminalAtPath = spawn("open", [
      "-a",
      "Terminal",
      codeDirectory, //make it so that this is the path to the current directory
    ]);
    openTerminalAtPath.on("error", (err) => {
      console.log(err);
    });
  });

  ipcMain.on("read-file", (event, filePath) => {
    //filePath is the relative path to the file. It should be a string.
    //read the file at filePath
    const fs = require("fs");
    const path = require("path");
    filePath = path.join(__dirname, "..", "..", filePath);
    console.log("reading file at path", filePath);
    fs.readFile(filePath, "utf8", (err, data) => {
      if (err) {
        console.error(err);
        return "500";
      }
      // send the data back to the renderer process
      console.log("sending data back to renderer process");
      event.sender.send("read-file-reply", data);
    });
  });
  // and load the index.html of the app.
  mainWindow.loadURL(MAIN_WINDOW_WEBPACK_ENTRY);

  // Open the DevTools.
  mainWindow.webContents.openDevTools();

  //watch for changes in the JSON folder and send a message to the renderer process when a change is detected
  const watcher = chokidar.watch(
    path.join(__dirname, "..", "..", "..", "/data-store"),
    {
      ignored: /(^|[\/\\])\../, // Ignore dotfiles
      persistent: true,
    }
  );

  watcher.on("change", (path) => {
    console.log("change detected at path", path);
    //edit the path to only include the JSON file name
    path = path.split("/");
    path = path[path.length - 1];
    console.log("sending fileChanged message to renderer process");
    mainWindow.webContents.send("file-changed", path);
  });
};

// This method will be called when Electron has finished
// initialization and is ready to create browser windows.
// Some APIs can only be used after this event occurs.
app.on("ready", createWindow);

// Quit when all windows are closed, except on macOS. There, it's common
// for applications and their menu bar to stay active until the user quits
// explicitly with Cmd + Q.
app.on("window-all-closed", () => {
  if (process.platform !== "darwin") {
    app.quit();
  }
});

app.on("activate", () => {
  // On OS X it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow();
  }
});
