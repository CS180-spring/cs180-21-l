import React, { createContext, useContext, useState } from "react";

// Create a new context for storing the JSON file path
const JSONFilePathContext = createContext();

// Custom hook for accessing the JSON file path context
export const useJSONFilePath = () => useContext(JSONFilePathContext);

// Provider component for the JSON file path context
export const JSONFilePathProvider = ({ children }) => {
  const [filePath, setFilePath] = useState("");
  if (filePath !== "") {
    console.log("filePath:", filePath);
  }

  return (
    <JSONFilePathContext.Provider value={{ filePath, setFilePath }}>
      {children}
    </JSONFilePathContext.Provider>
  );
};
