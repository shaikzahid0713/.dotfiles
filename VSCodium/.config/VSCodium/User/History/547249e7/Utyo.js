import react, { Component } from 'react';

class CarList extends Component {
    render() {
        return (
             <div></div>
        );
    }
    
    constructor(props) {
        super(props);
        this.state = {cars : [] };
    }
    
    componentDidMount() {
        fetch('htt')
    }
}

export default CarList;
