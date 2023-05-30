import * as React from "react";
import {
  Pane,
  Text,
  majorScale,
  minorScale,
  IconButton,
  Button,
  TrashIcon,
  EditIcon,
  RefreshIcon,
  DatabaseIcon,
  ExchangeIcon,
  Heading,
} from "evergreen-ui";

import { useJSONFilePath } from "../Contexts/JSONFilePathContext";

export default function Sidebar({ contentChange }) {
  const { filePath, setFilePath } = useJSONFilePath();
  return (
    <Pane
      id="sidebar"
      display="flex"
      flexDirection="column"
      alignItems="center"
      justifyContent="start"
      backgroundColor="#F8F8F8"
      height="100vh"
      flex="1"
      position="relative"
      minWidth="250px"
      maxWidth="300px"
      padding={majorScale(2)}
    >
      <Pane
        display="flex"
        flexDirection="row"
        alignItems="baseline"
        justifyContent="start"
        width="100%"
        marginBottom={majorScale(2)}
      >
        <Heading size={800} marginTop={10}>
          Movie Documents
        </Heading>
      </Pane>
      <Pane
        id="Document Buttons"
        display="flex"
        flexDirection="row"
        alignItems="center"
        width="100%"
      >
        <IconButton icon={RefreshIcon} marginRight={majorScale(2)} />
        <IconButton icon={EditIcon} marginRight={majorScale(2)} />
        <IconButton
          icon={TrashIcon}
          intent="danger"
          marginRight={majorScale(2)}
        />
      </Pane>
      <Pane
        display="flex"
        flexDirection="row"
        alignItems="baseline"
        justifyContent="start"
        width="100%"
        gap={minorScale(2)}
        marginBottom={majorScale(2)}
      >
        <DatabaseIcon color="#8f95b2" />
        <Text size={500} color="#8f95b2" marginTop={majorScale(2)}>
          Source Database
        </Text>
      </Pane>
      <Pane
        display="flex"
        flexDirection="column"
        width="100%"
        gap={minorScale(2)}
      >
        <Button
          width="100%"
          justifyContent="start"
          padding={minorScale(2)}
          iconBefore={DatabaseIcon}
          onClick={() => {
            console.log("Clicked Movies.json");
            contentChange("Movies.json", "Movies.json");
            setFilePath("../../../data-store/Movies.json");
          }}
        >
          Movies.json
        </Button>
        <Button
          width="100%"
          justifyContent="start"
          padding={minorScale(2)}
          iconBefore={DatabaseIcon}
          onClick={() => {
            contentChange("People.json", "People.json");
            console.log("Clicked People.json");
          }}
        >
          People.json
        </Button>
      </Pane>
      <Pane
        display="flex"
        flexDirection="row"
        alignItems="baseline"
        justifyContent="start"
        width="100%"
        gap={minorScale(2)}
        marginBottom={majorScale(2)}
      >
        <ExchangeIcon color="#8f95b2" />
        <Text size={500} color="#8f95b2" marginTop={majorScale(2)}>
          Relational Database
        </Text>
      </Pane>
      <Pane
        display="flex"
        flexDirection="column"
        width="100%"
        gap={minorScale(2)}
      >
        <Button
          width="100%"
          justifyContent="start"
          padding={minorScale(2)}
          iconBefore={DatabaseIcon}
          onClick={() => {
            contentChange("Acted_In.json", "descirption");
            console.log("Clicked People.json");
          }}
        >
          Acted_In.json
        </Button>
        <Button
          width="100%"
          justifyContent="start"
          padding={minorScale(2)}
          iconBefore={DatabaseIcon}
          onClick={() => {
            contentChange("Acted_By.json", "decription");
            console.log("Clicked People.json");
          }}
        >
          Acted_By.json
        </Button>
      </Pane>
    </Pane>
  );
}
