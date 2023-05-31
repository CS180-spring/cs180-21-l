// See the Electron documentation for details on how to use preload scripts:
// https://www.electronjs.org/docs/latest/tutorial/process-model#preload-scripts
const { contextBridge, ipcRenderer } = require("electron");

contextBridge.exposeInMainWorld("electronAPI", {
  setTitle: (title) => ipcRenderer.send("set-title", title),
  openTerminal: () => ipcRenderer.send("open-terminal"),
  readFile: (filePath) => ipcRenderer.send("read-file", filePath),
  onReadFileReply: (callback) =>
    ipcRenderer.on("read-file-reply", (event, data) => {
      console.log("data type:", typeof data);
      callback(data);
    }),
});
