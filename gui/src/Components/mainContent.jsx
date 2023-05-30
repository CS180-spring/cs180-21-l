import * as React from "react";
import {
  Button,
  Pane,
  Text,
  majorScale,
  Heading,
  Menu,
  Popover,
  PeopleIcon,
  EditIcon,
  TrashIcon,
} from "evergreen-ui";
import DataTable from "./dataTable";

export default function MainContent(props) {
  window.electronAPI.setTitle(props.title);
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
          <Popover
            content={
              <Menu>
                <Menu.Group>
                  <Menu.Item icon={PeopleIcon}>Share...</Menu.Item>
                  <Menu.Item icon={EditIcon}>Edit...</Menu.Item>
                </Menu.Group>
                <Menu.Divider />
                <Menu.Group>
                  <Menu.Item icon={TrashIcon} intent="danger">
                    Delete...
                  </Menu.Item>
                </Menu.Group>
              </Menu>
            }
          >
            <Button>Options</Button>
          </Popover>
          <Button appearance="primary">Add</Button>
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
        <DataTable />
      </Pane>
    </Pane>
  );
}
