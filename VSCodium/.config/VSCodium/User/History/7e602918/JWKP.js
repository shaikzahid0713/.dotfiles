import logo from './logo.svg';
import './App.css';
import { AppBar, Toolbar, Typography } from '@material-ui/core';
import CarList from './components/carList';

function App() {
  return (
    <div className="App">
      <AppBar position='static' color='default'>
        <Toolbar>
          <Typography variant='h6' color='inherit'>
            CarList
          </Typography>
        </Toolbar>
      </AppBar>
      <CarList />
    </div>
  );
}

export default App;
