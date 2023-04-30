import * as React from "react";
import { Button, Pane, Text, majorScale } from "evergreen-ui";

export default function Hello() {
  return (
    <>
      <h2>Hello from React!</h2>
      <Pane display="flex" alignItems="center" marginX={majorScale(2)}>
        <Button>Click me!</Button>
        <Text>This is a clickable Button</Text>
      </Pane>
    </>
  );
}
