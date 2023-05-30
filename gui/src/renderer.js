/**
 * This file will automatically be loaded by webpack and run in the "renderer" context.
 * To learn more about the differences between the "main" and the "renderer" context in
 * Electron, visit:
 *
 * https://electronjs.org/docs/tutorial/application-architecture#main-and-renderer-processes
 *
 * By default, Node.js integration in this file is disabled. When enabling Node.js integration
 * in a renderer process, please be aware of potential security implications. You can read
 * more about security risks here:
 *
 * https://electronjs.org/docs/tutorial/security
 *
 * To enable Node.js integration in this file, open up `main.js` and enable the `nodeIntegration`
 * flag:
 *
 * ```
 *  // Create the browser window.
 *  mainWindow = new BrowserWindow({
 *    width: 800,
 *    height: 600,
 *    webPreferences: {
 *      nodeIntegration: true
 *    }
 *  });
 * ```
 */

import "./index.css";

export function fetchDocumentsFromStorage() {
  //we expect an array of objects from the main process
  console.log("sending FETCH_DOCUMENTS_FROM_STORAGE to main process");
  ipcRenderer.send(FETCH_DOCUMENTS_FROM_STORAGE, "items");
}

export function saveDocumentToStorage(item) {
  console.log("sending SAVE_DOCUMENTS_TO_STORAGE to main process");
  ipcRenderer.send(SAVE_DOCUMENTS_TO_STORAGE, item);
}

export function removeDocumentFromStorage(item) {
  console.log("sending REMOVE_DOCUMENTS_FROM_STORAGE to main process");
  ipcRenderer.send(REMOVE_DOCUMENTS_FROM_STORAGE, item);
}

import "./app.jsx";
