let history = History.createBrowserHistory();

AppShell.bootstrap(history) |> AppShell.onLocationChange(history##location);