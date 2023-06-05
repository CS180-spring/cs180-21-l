import * as React from "react";
import {
  Pane,
  minorScale,
  Heading,
  ConsoleIcon,
  IconButton,
  ThemeProvider,
  defaultTheme,
  CornerDialog,
} from "evergreen-ui";

import { merge } from "lodash";
import MainContent from "../Components/mainContent";
import Sidebar from "../Components/Sidebar";
import EmptyMain from "../Components/emptyMain";
import { JSONFilePathProvider } from "../Contexts/JSONFilePathContext";

const myTheme = merge({}, defaultTheme, {
  fontFamilies: {
    display: '"JetBrains Mono"',
    ui: '"JetBrains Mono"',
  },
});

export default function Homepage() {
  const [content, setContent] = React.useState(<EmptyMain />);
  const [dialogShown, setDialogShown] = React.useState(false);

  function handleContent(name, desp) {
    setContent(<MainContent title={name} description={desp} />);
  }

  return (
    <>
      <JSONFilePathProvider>
        <Pane
          id="wrapper"
          display="flex"
          flexDirection="row"
          width="100%"
          height="100%"
        >
          <Sidebar contentChange={handleContent} />
          <Pane
            id="mainContent"
            display="flex"
            flex="4"
            justifyContent="center"
            flexDirection="column"
          >
            {content}
            <Pane
              id="terminal-bar"
              display="flex"
              position="relative"
              backgroundColor="#404040"
              padding={minorScale(2)}
              alignItems="center"
              justifyContent="space-between"
            >
              <ThemeProvider value={myTheme}>
                <Heading size={400} color="white">
                  TERMINAL
                </Heading>
              </ThemeProvider>
              <IconButton
                icon={ConsoleIcon}
                marginRight={minorScale(2)}
                onClick={() => {
                  window.electronAPI.openTerminal();
                  setDialogShown(true);
                }}
              />
              <CornerDialog
                title="Terminal Opened"
                isShown={dialogShown}
                onCloseComplete={() => setDialogShown(false)}
                hasFooter={false}
              >
                Terminal has been opened in a new window and is navigated to the
                root of the C++ project.
              </CornerDialog>
            </Pane>
          </Pane>
        </Pane>
      </JSONFilePathProvider>
    </>
  );
}
