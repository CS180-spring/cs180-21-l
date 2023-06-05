import * as React from "react";
import { Button, Pane, Text, majorScale, Heading, toaster } from "evergreen-ui";
import DataTable from "./dataTable";
import { useJSONFilePath } from "../Contexts/JSONFilePathContext";

export default function MainContent(props) {
  const { filePath, setFilePath } = useJSONFilePath();
  window.electronAPI.setTitle(props.title);

  function handleRefresh() {
    toaster.notify("Refreshing data...");
    if (filePath !== "" && filePath !== null) {
      window.electronAPI.readFile(filePath);
    }
  }
  function handleDataTableRefresh() {
    handleRefresh();
  }

  return (
    <Pane
      display="flex"
      height="100%"
      width="100%"
      padding={majorScale(2)}
      flexDirection="column"
      gap={majorScale(2)}
    >
      <Pane
        display="flex"
        flexDirection="row"
        justifyContent="space-between"
        alignItems="baseline"
      >
        <Heading size={900} marginTop={52}>
          {props.title}
        </Heading>
        <Pane gap={majorScale(2)} display="flex">
          <Button
            appearance="primary"
            onClick={() => {
              handleRefresh();
            }}
          >
            Refresh
          </Button>
        </Pane>
      </Pane>
      <Pane display="flex" flexDirection="column" width="100%">
        <Text>{props.description}</Text>
      </Pane>
      <Pane
        display="flex"
        flexDirection="column"
        width="100%"
        marginTop={majorScale(4)}
      >
        <DataTable refresh={handleDataTableRefresh} />
      </Pane>
    </Pane>
  );
}
